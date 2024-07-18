//*****************************************                                                                                                                                                                 
// ** File:    MoviePlayer.cpp                                                                                                                                                                                    
                                                                                                                                                                             
                                                                                                                                                                          
// **                                                                                                                                                                                                       
//**serves as the implementation of a movie player application. It defines the MoviePlayer class along with its member functions, which collectively handle various aspects of the application's
//**functionality. This includes loading movie data from a file into a catalog, presenting users with a main menu offering options to interact with the player, and facilitating actions such as
//**displaying movies based on user-defined criteria like year and genre. Additionally, the file enables users to add movies to a playlist, view the contents of the playlist, and sort the playlist
//**based on movie release year                                                                                                                                                                             
//***********************************************/






#include "MoviePlayer.h"


//Name: MoviePlayer - Default Constructor
//PreCondition: None
//PostCondition:Creates a new MoviePlayer with m_filename of "proj5_movies.txt"
MoviePlayer::MoviePlayer() {
  m_filename = "proj5_movies.txt"; 
}


//Name: MoviePlayer - Overloaded Constructor
//PreCondition: None
//PostCondition: Creates a new MoviePlayer with passed filename     
MoviePlayer:: MoviePlayer(string filename) {
  m_filename = filename;
}


//Name:  ~MoviePlayer - Destructor
//PreCondition: None
//PostCondition: Deallocates movies from m_movieCatalog       
MoviePlayer:: ~MoviePlayer() {
  for (size_t i = 0; i < m_movieCatalog.size(); i++) {
    delete m_movieCatalog[i];    
  }  
}


//Name: LoadCatalog()
//PreCondition: m_filename must have name of file
//PostCondition: If the file specified by m_filename can be opened successfully for reading:The function reads data for each movie from the file, line by line.
//For each movie, it extracts information such as title, rating, genre, year, director, star, budget, gross, studio, and runtime.
//It dynamically allocates memory for a new Movie object using the extracted information. The newly created Movie object is added to the m_movieCatalog vector.
//If any line in the file contains invalid movie data, it skips that line and continues to the next one.
void MoviePlayer::LoadCatalog() {
  ifstream inputFile(m_filename);      //an input file stream used to read data from the file
    if (!inputFile.is_open()) {
        cerr << "Error: File could not open! " << m_filename << endl;
        return;
    }

    string line;   //A string variable used to store each line read from the input file
    while (getline(inputFile, line)) {
        istringstream iss(line);   
        string title, rating, genre, director, star, studio;    //String variables used to store information about each movie.
        string yearStr, budgetStr, grossStr, runtimeStr;       //String variables used to store raw string representations of numeric data (year, budget, gross, runtime) read from the file.

              // Read data for a movie from the current line
              if (!(getline(iss, title, ';') &&
              getline(iss, rating, ';') &&
              getline(iss, genre, ';') &&
              getline(iss, yearStr, ';') &&
              getline(iss, director, ';') &&
              getline(iss, star, ';') &&
              getline(iss, budgetStr, ';') &&
              getline(iss, grossStr, ';') &&
              getline(iss, studio, ';') &&
              getline(iss, runtimeStr))) {
            cerr << "Error: Invalid movie data!" << endl;

	    // Skip to the next line if movie data is invalid    
	    continue; 
             }

  
        // Convert string parameters to appropriate types
	int year = stoi(yearStr);       //stores converted values of year of movie from string    
        long budget = stol(budgetStr);  //stores converted values of budget  of movie from string   
        long gross = stol(grossStr);     //stores converted values of gross of movie from string   
        int runtime = stoi(runtimeStr);    //stores converted values of runtime of movie from string   

        // Dynamically allocate a new Movie object and add it to the movie catalog
        Movie* movie = new Movie(title, rating, genre, year, director, star, budget, gross, studio, runtime);   //A pointer to a Movie object dynamically allocated for each movie read from the file.
        m_movieCatalog.push_back(movie);
    }

    inputFile.close();
}


//Name:  MainMenu
//PreCondition: None
//PostCondition: Manages menu and asks user what to do until user chooses to quit 
void MoviePlayer::MainMenu() {
  int userChoice;   //store the user's menu choice 
  cout << "5340 movie files loaded." <<endl; 
  do {
    cout << "What would you like to do?" << endl;
    cout << "1. Display Movie by Type and Year" << endl;
    cout << "2. Add Movie to Playlist" << endl; 
    cout << "3. Display Playlist" << endl;
    cout << "4. Sort Playlist by Year" << endl;
    cout << "5. Quit" << endl;
    cin >> userChoice;


        if (userChoice == 1) {
            DisplayMovie();
        } else if (userChoice == 2) {
            AddMovie();
        } else if (userChoice == 3) {
            DisplayPlaylist();
        } else if (userChoice == 4) {
            SortPlaylist();
        } else if (userChoice == 5) {
            cout << "Thank you for using the UMBC Movie Player!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    //loop will run until user enters an option other than 5 which is to quit 
  } while (userChoice != 5);
}


//Name: DisplayMovie
//PreCondition: m_movieCatalog, MIN_YEAR, and MAX_YEAR are all populated
//PostCondition: The function displays a prompt asking the user to input a year and a genre for filtering movies.
//After the user inputs a year and a genre, the function searches through the movie catalog for movies matching the specified year and genre.
//If matching movies are found, their details are displayed along with their index positions in the catalog.
//If no matching movies are found, a message indicating this is displayed.The function returns the number of movies found that match the specified year and genre.
int MoviePlayer::DisplayMovie() {
  int yearOfMovie;      //store the user's input for the year of the movies they want to display.
  string genreOfMovie;    //store the user's input for the genre of the movies they want to display.
  
  cout << "Which year would you like to display? " << "(" <<MIN_YEAR << " - " <<MAX_YEAR  << ")" << endl; 

  cin >> yearOfMovie;
  cout << "******" << yearOfMovie << "*****" <<endl; 
  cout << "Which genre would you like? " << endl;
  cin >> genreOfMovie;
  cout << "******" << genreOfMovie << "*****" <<endl;
  cout << "MOVIES TOTAL: 5340 " <<endl; 
  
  int counter = 0;      //count the number of movies found that match the specified year and genre.

  // iterates through each movie in the catalog, checks if the movie matches the specified year and genre, and prints its index and details if it does.
  for (size_t i = 0; i < m_movieCatalog.size(); ++i) {
    Movie* movies = m_movieCatalog[i];     // access movie information during the iteration over the catalog.

    if (movies->GetYear() == yearOfMovie && movies->GetGenre() == genreOfMovie) {
      cout << i+1 << " " << *movies << endl; 
      counter ++; 
    }
    
  }

  if (counter == 0) {
    cout << "No matching movies found" <<endl; 
  } else {
    cout << counter << " movies found." << endl;
  }
  
  return counter; 
}


//Name: AddMovie
//PreCondition: m_movieCatalog is populated
//PostCondition:  After execution, the chosen movie, if valid, is added to the playlist, and a confirmation message is displayed. If the playlist was initially empty, it informs the user, and if the user input was invalid, it prompts them to try again.
void MoviePlayer::AddMovie() {

    if (m_playList.IsEmpty()) {
      cout << "The playlist is currently empty." << endl;
    } else {
       DisplayPlaylist();
    }

    cout << "Choose the movie you would like to add to the playlist." <<endl;

    int occurence = DisplayMovie();     //Stores the result of the DisplayMovie() function. 
  if (occurence == 0) {
    return; 
  }

  int number;    //: Stores the user's input for the movie number they want to add. 
  cout << "Enter the number of the movie you would like to add: " <<endl;
  cin >> number;

   if (number < 0 || number > static_cast<int>(m_movieCatalog.size())) {
    cout << "Invalid movie number. Please try again." << endl;
    return;
  }

  Movie* chosenMovie = m_movieCatalog[number-1];   //Pointer to the chosen movie object retrieved from the movie catalog.
  m_playList.PushBack(chosenMovie);
  cout <<chosenMovie->GetTitle() << " by " << chosenMovie->GetDirector() << " from " << chosenMovie->GetYear() << " " <<"added to the playlist."  <<endl;

}


//Name: DisplayPlaylist
//PreCondition: None
//PostCondition:  After execution, the function displays the movies in the playlist along with their details, numbering each entry. If the playlist is empty, it informs the user.
void MoviePlayer::DisplayPlaylist() {
    if (m_playList.IsEmpty()) {
        cout << "The playlist is currently empty." << endl;
        return;
    }

    Queue<Movie*> tempPlaylist = m_playList;  //A temporary copy of the playlist to avoid modifying the original playlist.
    size_t index = 1; // Initialize index for numbering the playlist entries

    while (!tempPlaylist.IsEmpty()) {
        Movie* current = tempPlaylist.Front(); // Get the front movie
        cout << index << ". " << *current << endl; 
        tempPlaylist.PopFront();

	// Increment index for the next movie  
        index++; 
    }
}



//Name: SortPlaylist
//PreCondition: None
//PostCondition: Sorts playlist by year            
void MoviePlayer::SortPlaylist() {
  if (m_playList.IsEmpty()) {
      cout << "The playlist needs at least two movies to sort." << endl;
      return;
  }

  
  
  m_playList.Sort();
  cout << "Done sorting by year" << endl;

  // line indicates how many items are currently in the playlist after the sorting operation.
  cout << m_playList.GetSize() << " items sorted." << endl;
}



//Name: StartPlayer
//PreCondition: None
//PostCondition: Loads file and calls main menu 
void MoviePlayer::StartPlayer() {
 
  LoadCatalog(); 
    MainMenu();
}
