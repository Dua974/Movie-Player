//*****************************************
// ** File:    Queue.cpp

// **
//**It contains the definitions of various functions associated with the Queue class, including constructors, destructor, copy constructor, overloaded assignment
//**operator, methods for adding and removing elements, as well as functions for accessing and manipulating the queue. Additionally, it provides functionality for sorting the elements of the queue
//**and performing various operations such as finding elements, clearing the queue, and swapping elements. The file also includes the definition of the Node class, which represents individual nodes
//**in the linked list
//***********************************************/




#ifndef QUEUE_CPP
#define QUEUE_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Templated linked list
//Note: Because the linked list is a templated class,
//      there is only ONE file (Queue.cpp)

//Templated node class
template <class T>
class Node {
public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = NULL;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
   return m_data;
}

//Sets the data in a Node
template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Queue {
 public:
  // Name: Queue() Queue from a linked list - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new queue where m_head and m_tail
  //                 point to nullptr and m_size = 0
  Queue();
  // Name: ~Queue() - Destructor
  // Desc: Used to destruct a Queue
  // Preconditions: There is a Queue
  // Postconditions: Queue is deallocated (including dynamically allocated nodes)
  //                 Can just call Clear()
 ~Queue();
  // Name: Queue (Copy Constructor)
  // Preconditions: Creates a copy of existing Queue in separate memory
  //                address (deep copy)
  //                Requires one already existing Queue
  // Postconditions: Copy of existing Queue
  Queue(const Queue&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: When two Queue objects exist, sets one to equal another
  //                Requires two Queue objects
  // Postconditions: When completed, you have two Queues in
  //                 separate memory addresses with the same
  //                 number of nodes with the same values in each node
  Queue<T>& operator= (Queue&);
  // Name: PushBack
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Queue
  // Postconditions: Adds a new node to the end of the Queue.
  void PushBack(const T&);
  // Name: PopFront
  // Preconditions: Queue with at least one node. 
  // Postconditions: Removes first node in the queue and
  //                 returns the data in the first node
  T PopFront();
  // Name: Display
  // Preconditions: Outputs the queue.
  // Postconditions: Displays the data in each node of queue
  // Required (used only for queue testing)
  void Display();
  // Name: Front
  // Preconditions: Requires a Queue with at least one node
  // Postconditions: Returns whatever data is pointed at by m_head -
  //                 Does NOT remove node
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a queue
  // Postconditions: Returns if the queue is empty.
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires a queue
  // Postconditions: Returns m_size
  int GetSize();
  // Name: Find()
  // Preconditions: Requires a queue
  // Postconditions: Iterates and if it finds the thing, returns index, else -1
  int Find(T);
  // Name: Clear
  // Preconditions: Requires a queue
  // Postconditions: Deallocates and removes all nodes in a queue. No memory leaks
  void Clear();
  // Name: At
  // Precondition: Existing Queue
  // Postcondition: Returns object from Queue at a specific location
  // Desc: Iterates to node x and returns data from Queue
  T& At (int x);
  // Name: Swap(int)
  // Preconditions: Requires a queue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  // Example: Swap(1) would swap the node 0 with node 1 so
  //          that node 1 would now be m_head
  // Desc: Swaps two nodes by updating the pointers (not just the value)
  // Hint: Think about the special cases! Implement before Sort
  void Swap(int);
  // Name: Sort()
  // Preconditions: Requires a queue with a minimum of 2 nodes
  //                (otherwise notifies user)
  // Postconditions: Sorts the Queue (may use overloaded < or >).
  // Desc: This is used to sort anything in the Queue assuming the
  //       < or > is overloaded
  //        Uses bubble sort and Swap function above.
  //        Ensure working with queue_test before rest of project.
  // Note: Allowed to use the break command in just this function if necessary
  void Sort();
private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};

//**********Implement Queue Class Here***********
//**********All Functions Are Required Even If Not Used for Project**************
//**********No references to anything from Movie here*****************


//Name: Queue() - Default Constructor
//PreCondition: None
//PostCondition: Creates new queue where head and tail point to nullptr and m_size = 0
template <class T>
Queue<T>::Queue() {      
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}


//Name: ~Queue() - Destructor
//PreCondition: There is a Queue
//PostCondition: Queue is deallocated
template <class T>
Queue<T>:: ~Queue() {        
  Clear();
}



//Name: Queue (Copy Constructor)
//PreCondition: Creates a copy of existing Queue in separate memory    
//PreCondition: A new Queue object is created with the same elements and order as the otherQueue parameter.
//The current queue (this) has its head (m_head), tail (m_tail), and size (m_size) updated to reflect the copied elements from otherQueue.
//The original order of elements in otherQueue is preserved in the newly created queue (newQueue), and then these elements are copied back into the current queue. 
template <class T>
Queue<T>::Queue(const Queue<T>& otherQueue) {
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;

  // Create a temporary queue to preserve the original order of elements
  Queue<T> newQueue;  //Temporary queue used to preserve the original order of elements from otherQueue.

  // Iterate through the other queue and copy elements to the temporary queue
  Node<T>* currentNode = otherQueue.m_head;  //Pointer to traverse through the nodes of otherQueue making copying process easier

  while (currentNode != nullptr) {
      newQueue.PushBack(currentNode->GetData());
      currentNode = currentNode->GetNext();
  }

  // Iterate through the temporary queue and copy elements to the current queue
  while (!newQueue.IsEmpty()) {
      PushBack(newQueue.Front());
      newQueue.PopFront();
  }
  
}


//Name: operator= (Overloaded Assignment Operator)
//PreCondition: When two Queue objects exist, sets one to equal another
//PostCondition: The current queue (this) is assigned the elements and order of the anotherQueue parameter.
//If this is not the same as anotherQueue, the current queue is cleared, and then the elements of anotherQueue are copied into it.The original order of elements in
//anotherQueue is preserved in the current queue (this).
template <class T>
Queue<T>& Queue<T>::operator=(Queue<T>& anotherQueue) {
    if (this != &anotherQueue) {
        Clear();
        Node<T>* currentNode = anotherQueue.m_head;   // Pointer to traverse through the nodes of anotherQueue, facilitating the copying process.

	//iterating over each node of the anotherQueue and copying its data into the current queue
        while (currentNode != nullptr) {
            PushBack(currentNode->GetData());
            currentNode = currentNode->GetNext();
        }
    }
    return *this;
}




//Name: PushBack
//PreCondition: Takes in data. Creates new node.
//PostCondition: The data provided is added to the back of the queue.The size of the queue (m_size) is incremented by 1.
template <class T>
void Queue<T>::PushBack(const T& data) {       
   
    // Create a new node with the provided data
  Node<T>* newlyCreatedNode = new Node<T>(data);    // A pointer to the newly created node containing the provided data.
  
    newlyCreatedNode->SetNext(nullptr);  

      
    // If the queue is empty, set both head and tail to the new node
    if (IsEmpty()) {
        m_head = newlyCreatedNode;
        m_tail = newlyCreatedNode;;
    } else {
        // Otherwise, set the next pointer of the current tail to the new node
        m_tail->SetNext(newlyCreatedNode);

        // Update m_tail to point to the new node
        m_tail = newlyCreatedNode;
    }

    // Increment the size of the queue
    m_size++;
}



//Name: PopFront
//PreCondition: Queue with at least one node.
//PostCondition: The first element of the queue is removed.
//If the queue becomes empty after the removal, both m_head and m_tail are set to nullptr. The size of the queue (m_size) is decremented by 1.
template <class T>
T Queue<T>::PopFront() {
    // Check if the queue is empty
    if (IsEmpty()) {
        throw "Empty";
    }

    // Get data from the first node
    T nodeData = m_head->GetData();     //Stores the data of the node being removed, which is returned after removal.

    // Update m_head to point to the next node
    Node<T>* head = m_head;     //Temporary pointer to the node at the front of the queue, used for deletion
    
    m_head = m_head->GetNext();

    // Delete the old head node
    delete head;

    // If the queue is now empty, update m_tail to nullptr
    if (m_head == nullptr) {
        m_tail = nullptr;
    }

    // Decrement the size of the queue
    m_size--;

    return nodeData;
}


//Name: Display
//PreCondition: Outputs the queue.
//PostCondition: The function iterates through each node of the queue and displays the data contained in each node.
//Each data element is printed to the console followed by a newline character.
template <class T>
void Queue<T>::Display() {        
  Node<T>* currentNode = m_head;     //A pointer to traverse the nodes of the queue.
  
  while(currentNode != nullptr) {
    cout << currentNode -> GetData() << endl;     
    currentNode = currentNode->GetNext();
  }

  cout << endl; 
}



//Name: Front
//PreCondition: Requires a Queue with at least one node
//PostCondition: If the queue is not empty (m_head != nullptr), the function returns the data stored in the first node of the queue (m_head->GetData()).
template <class T>
T Queue<T>::Front() {
      return (m_head != nullptr) ? m_head->GetData() : throw " empty";
}


// Name: IsEmpty                                                                                                                                                                                          
// Preconditions: Requires a queue                                                                                                                                                                        
// Postconditions: Returns if the queue is empty.                            
template <class T>
bool Queue<T>::IsEmpty() {       
  return !m_head;
}


// Name: GetSize                                                                                                                                                                                          
// Preconditions: Requires a queue                                                                                                                                                                        
// Postconditions: Returns m_size                                          
template <class T>
int Queue<T>::GetSize() {
    return m_size;
}



//Name: Find()
//PreCondition: Requires a queue
//PostCondition: if the target element is found in the queue, the function returns the index (zero-based) of the first occurrence of the target element.
//If the target element is not found in the queue, the function returns -1.
template <class T>
int Queue<T>::Find(T target) {
  int indexOfTarget = 0;         //keep track of the index (position) of the target element within the queue.
  
  Node<T>* currentNode = m_head;   //pointer to traverse the queue from the head node to the tail node.

  while(currentNode!= nullptr) {

    //when the condition currentNode->GetData() == target evaluates to true, it means that the data stored in the current node matches the target value.
    if(currentNode->GetData() == target) {
      return indexOfTarget;
    
    }
    currentNode = currentNode->GetNext();
    indexOfTarget++;
  
  }
  return -1;
}



//Name: Clear
//PreCondition: Requires a queue
//PostCondition: Deallocates and removes all nodes in a queue. No memory leaks 
template <class T>
void Queue<T>::Clear() {              
  Node<T>* currentNode = m_head;   //Pointer to traverse the queue and deallocate each node
  
  //iterate until currentNode is empty 
  while(currentNode != nullptr) {

    //a temporary variable to hold the current node 
    Node<T>* NodeToDelete = currentNode;    // Temporary pointer used to hold the current node to be deleted before moving to the next node.

    //Current Node set to next node so then we can delete the node we are on 
    currentNode = currentNode->GetNext();
   
    delete NodeToDelete;
  }

  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}



//Name: At
//PreCondition: Existing Queue
//PostCondition: If successful, returns a reference to the data at the specified index x in the queue.Throws an exception if the index is out of bounds or if the queue is empty.
template <class T>
T& Queue<T>::At(int x) {

  //if node is in index < 0 or is outside of the length of the queue then it is out of bounds 
  if (x < 0 || x >= m_size) {
    throw "Index out of bounds";
  }
  
  Node<T>* currentNode = m_head;   //Pointer to traverse the queue and locate the node at the specified index.
  int index = 0;    //keep track of the current index while traversing
  
  while (index < x && currentNode != nullptr) {
    
    //keep setting currentNode to the next node until we reach the node at index x
    currentNode = currentNode->GetNext();
    index ++; 
  }
  if (currentNode == nullptr) {       
    throw "Index is out of bounds";
  }

  
  return currentNode->GetData();
}


//Name: Swap(int)
//PreCondition: Requires a queue
//PostCondition: If successful, swaps the node at the specified index with the node next to it.If the index is out of bounds or if the queue has less than two elements, prints "Invalid index" and returns without performing any swap.
template <class T>
void Queue<T>::Swap(int index) {
  
  if (index <= 0 || index >= m_size) {
    cout << "Invalid index." <<endl; 
    return;
  }

  Node<T>* currentNode = m_head;     //Pointer to the current node being processed during the traversal of the queue.
  
  Node<T>* prevNode = nullptr;    // Pointer to the node before the current node.

  for (int i = 0; i < index; i++) {
      if (i == index - 1) {
          break;
      }
      prevNode = currentNode;
      currentNode = currentNode->GetNext();
  }
  

  Node<T>* nextNode = currentNode->GetNext();    //Pointer to the node after the current node.

    if (index == 1) {
    m_head = nextNode;
    currentNode->SetNext(nextNode->GetNext());

    //setting the next pointer of the node pointed to by nextNode to point to the node pointed to by currentNode.
    nextNode->SetNext(currentNode);
    if (currentNode == m_tail || nextNode == m_tail) {
      m_tail = currentNode == m_tail ? nextNode : currentNode;
    }
    return;
  }

  //checks if the node to be swapped is the last node in the queue
  if (index == m_size - 1) {
    prevNode->SetNext(nextNode);

    //updates the next pointer of the currentNode to point to the node after nextNode, essentially skipping nextNode in the sequence.
    currentNode->SetNext(nextNode->GetNext());
    nextNode->SetNext(currentNode);
    m_tail = currentNode;
    return;
  }

  // Handle general case
  prevNode->SetNext(nextNode);
  currentNode->SetNext(nextNode->GetNext());
  nextNode->SetNext(currentNode);
}





//Name: Sort()
//PreCondition: requires a queue with a minimum of 2 nodes
//PostCondtion: The queue is sorted in non-decreasing order based on the values of its elements.
template <class T>
void Queue<T>::Sort() {
  if (m_size < 2) {
    cout << "The playlist needs at least two movies to sort." << endl;
  }

  bool swapValue = true;    // tracks whether any swaps were made during a pass through the queue. If no swaps are made during a pass, it indicates that the queue is already sorted, and the sorting process can terminate.
  
  while (swapValue) {
    swapValue = false;    
    
    Node<T>* currentNode = m_head;    //pointer traverses the queue and points to the current node being examined during the sorting process.
    
    Node<T>* prevNode = nullptr;   //pointer points to the previous node relative to the currentNode

    while (currentNode->GetNext() != prevNode) {
        if (currentNode->GetData() > currentNode->GetNext()->GetData()) {
          
          T temporary = currentNode->GetData();


          //swaps the data between the current node and its next node in the queue, which is a key step in sorting the queue elements.
	  currentNode->SetData(currentNode->GetNext()->GetData());

          //swaps the data between the current node and its next node, achieving the swapping operation required for sorting the queue.
	  currentNode->GetNext()->SetData(temporary);
          swapValue = true;
        }

	//meaning there are no more nodes after the current one.
        currentNode = currentNode->GetNext(); 
    }
    prevNode = currentNode;

  }
}




#endif
