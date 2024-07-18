/*****************************************
** File:    Movie.cpp
** Author:  Dua Abdullah 

**
** file contains the implementation of the Movie class, which represents individual movies within the movie player application. It defines various member
**functions to initialize, access, and modify attributes such as title, rating, genre, year, director, star, budget, gross, studio, and runtime for each movie object. Additionally, it overloads the
**stream insertion operator (<<) to allow for the convenient printing of movie details. Furthermore, the file includes overloaded comparison operators (< and >) to enable sorting movies based on
**their release years.
***********************************************/

#include "Movie.h"


//Name: Default Constructor
//PreCondition: None
//PostCondition: Creates a default movie 
Movie::Movie() {
    m_title = "";
    m_rating = "";
    m_genre = "";
    m_year = 0;
    m_director = "";
    m_star = "";
    m_budget = 0;
    m_gross = 0;
    m_studio = "";
    m_runtime = 0;
}


//Name:  Movie - Overloaded Constructor
//PreCondition: Requires title, rating, genre, year, director, star, budget, gross, studio, and runtime
//PostCondition:  Creates a movie entry based on passed parameters         
Movie::Movie(string title, string rating, string genre, int year, string director,
string star, long budget, long gross, string studio, int runtime) {
  
  m_title = title; 
  m_rating = rating; 
  m_genre = genre; 
  m_year = year; 
  m_director = director;
  m_star = star; 
  m_budget = budget;
  m_gross = gross; 
  m_studio = studio; 
  m_runtime = runtime; 
  
}


//Name: GetTitle()
//PreCondition: None
//PostCondition: return movie title 
string Movie:: GetTitle() const {
  return m_title; 
}

//Name: GetRating()                                                              
//PreCondition: None                                                            
//PostCondition: return movie rating    
string Movie::GetRating()const {
  return m_rating; 
}

//Name: GetGenre()                                                              
//PreCondition: None                                                            
//PostCondition: return movie genre    
string Movie::GetGenre()const {
  return m_genre; 
}

//Name: GetYear()                                                             
//PreCondition: None                                                            
//PostCondition: return movie year
int Movie::GetYear()const {
  return m_year;
}


//Name: GetDirector()                                                              
//PreCondition: None                                                            
//PostCondition: return movie director    
string Movie::GetDirector()const {
  return m_director; 
}


//Name: GetStar()                                                              
//PreCondition: None                                                            
//PostCondition: return movie star    
 string Movie::GetStar() const {
   return m_star;
 }

//Name: GetBudgete()                                                              
//PreCondition: None                                                            
//PostCondition: return movie budget
long Movie::GetBudget() const {
  return m_budget; 
} 

//Name: GetGross()                                                              
//PreCondition: None                                                            
//PostCondition: return movie gross   
 long Movie::GetGross() const {
   return m_gross;
 }

//Name: GetStudio()                                                              
//PreCondition: None                                                            
//PostCondition: return movie studio    
string Movie::GetStudio() const {
  return m_studio; 
}

//Name: GetRuntime()                                           
//PreCondition: None                                                            
//PostCondition: return movie runtime    
int Movie::GetRuntime() const {
  return m_runtime;
}

//Name: SetTitle()                                                        
//PreCondition: None                                                            
//PostCondition: sets movie's title    
void Movie::SetTitle(string title) {
  m_title = title; 
}


//Name: SetRating()                                                             
//PreCondition: None                                                           
                                                                                
//PostCondition: sets movie's rating                                             

void Movie::SetRating(string rating) {
  m_rating = rating; 
}

//Name: SetGenree()                                                             
//PreCondition: None                                                           
                                                                                
//PostCondition: sets movie's genre                                           
void Movie::SetGenre(string genre) {
    m_genre = genre;
}

//Name: SetYear()                                                            
//PreCondition: None                                                           
                                                                              
//PostCondition: sets movie's year                                           
void Movie::SetYear(int year) {
    m_year = year;
}

//Name: SetDirector()                                                                                                                     
//PreCondition: None                                                                                
//PostCondition: sets movie's director                                            
void Movie::SetDirector(string director) {
    m_director = director;
}

//Name: SetStar()                                                             
//PreCondition: None                                                           
                                                                                
//PostCondition: sets movie's star                                            
void Movie::SetStar(string star) {
    m_star = star;
}

//Name: SetBudget()                                                                                                                      
//PreCondition: None                                                                                
//PostCondition: sets movie's budget                                          
void Movie::SetBudget(long budget) {
    m_budget = budget;
}

//Name: SetGross()                                                            
//PreCondition: None                                                           
                                                                              
//PostCondition: sets movie's gross                                            
void Movie::SetGross(long gross) {
    m_gross = gross;
}

//Name: SetStudio()                                                             
//PreCondition: None                                                          
                                                                                
//PostCondition: sets movie's studio                                          
void Movie::SetStudio(string studio) {
    m_studio = studio;
}

//Name: SetRuntime()                                                             
//PreCondition: None                                                           
///PostCondition: sets movie's runtime                                            
void Movie::SetRuntime(int runtime) {
    m_runtime = runtime;
}

//Name: Overloaded << operator                                                                                                                                                                            
//Precondition: movie available                                                                                                                                                                           
//Postcondition: Returns output stream including title by director from year                                                                         
ostream& operator<<(ostream& out, Movie& m) {
  out << m.m_title << " by " << m.m_director << " from " << m.m_year;
  return out;
}


//Name: Overloaded Relational Operator (<)                                                                                                                                                                
//Precondition: Two movie objects required                                                                                                                                                                
//Postcondition: if passed movie's year is less than first, return true else false                                                                               
bool Movie::operator<(const Movie& m) {
    return m_year < m.m_year;
}


//Name: Overloaded Relational Operator (>)                                                                                                                                                                
//Precondition: Two movie objects required                                                                                                                                                                
//Postcondition: if passed movie's year is greater than first, returns true else false                                                                                                                                
bool Movie::operator>(const Movie& m) {
    return m_year > m.m_year;
}
