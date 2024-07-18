<p align="center"> 
  <img src="images/movie.png" alt="Movie Player" width="210px" height="210px">
</p>
<h1 align="center"> Movie Player </h1>


<!-- TABLE OF CONTENTS -->
<h2 id="table-of-contents"> :book: Table of Contents</h2>

<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project"> ➤ About The Project</a></li>
    <li><a href="#overview"> ➤ Overview</a></li>
    <li><a href="#project-files-description"> ➤ Project Files Description</a></li>
    <li><a href="#getting-started"> ➤ Getting Started</a></li>

  </ol>
</details>


![--------------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<!-- ABOUT THE PROJECT -->
<h2 id="about-the-project"> :pencil: About The Project</h2>

<p>This project simulates a basic implementation of the Pokémon game franchise. Pokémon is a game where players act as trainers of creatures known as Pokémon, exploring the world to catch, train, and battle these creatures. The project uses a static list of 151 Pokémon with attributes such as name, combat points (CP), and rarity.
</p>

![------------------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<h2 id="overview"> :cloud: Overview</h2>
<p> This project is a robust tool designed to manage a vast catalog of movies, offering users a variety of functionalities: </p>

<ul>
  <li><strong>Display Movie by Type and Year:</strong> View movies based on specific genres and release years, facilitating easy exploration of diverse cinematic options.</li>
  <li><strong>Add Movie to Playlist:</strong> Dynamically add selected movies to a personalized playlist for seamless playback.</li>
  <li><strong>Display Playlist:</strong> View the current list of movies in the playlist, providing instant access to curated viewing experiences.</li>
  <li><strong>Sort Playlist by Year:</strong> Organize the playlist chronologically, from oldest to newest or vice versa, enhancing user control over playback preferences.</li>
  <li><strong>Quit: </strong> Exit the application with ease. </li>
</ul>

<p>The project leverages C++ to ensure efficient management of thousands of movie titles, offering a seamless viewing experience tailored to individual preferences and cinematic tastes.</p>


![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<!-- PROJECT FILES DESCRIPTION -->
<h2 id="project-files-description"> :floppy_disk: Project Files Description</h2>

<ul>
<li><strong>Movie.cpp:</strong> Implements the Movie class which contains all the information about each movie, such as title, rating, genre, year, director, star, budget, gross, studio, and runtime. This file also includes the overloaded < and > operators for sorting and operator for displaying movies.</li>

<li><strong>Movie.h:</strong> Header file defining the Movie class and its member function prototypes.</li>
<li><strong>MoviePlayer.cpp:</strong> Implements the MoviePlayer class which manages the master movie catalog and the user’s playlist. This file includes functionalities for displaying movies by type and year, adding movies to the playlist, displaying the playlist, and sorting the playlist by year.</li>
<li><strong>MoviePlayer.h:</strong> Header file defining the MoviePlayer class and its member function prototypes.</li>
<li><strong>Queue.cpp</strong> implements a templated linked list class Queue that allows users to PushBack (add to tail) and PopFront (remove from front). This file includes functionalities to display, return the data in the first node, return the size, and check if it is empty. It also includes a copy constructor and an overloaded assignment operator. The file should not reference any specific data type like Movie.</li>

<li><strong>makefile</strong> A makefile that contains rules for compiling the project and running tests. It includes specific rules for testing the Queue class.</li>

<li><strong>proj5</strong> The compiled executable file for the project.</li>

<li><strong>proj5.cpp:</strong> The main file that drives the entire program. It creates an instance of MoviePlayer and provides the user interface for interacting with the movie catalog and playlist.</li>

<li><strong>proj5_movies.txt: </strong> The input file containing the list of movies used to populate the movie catalog in the MoviePlayer class.</li>

<li><strong>qtest</strong> The compiled executable file for testing the Queue class.</li>
<li><strong>queue_test.cpp:</strong> A test file designed to test each of the major parts of the Queue class. This file is used to incrementally build and test the Queue functionalities.</li>
</ul>



![---------------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<!-- GETTING STARTED -->
<h2 id="getting-started"> :book: Getting Started</h2>

<p>Use the following command to clone the repository to your local machine:</p>
<pre><code>git clone git@github.com:YourGitHubUsername/Movie-Player.git</code></pre>
<p>Replace YourGitHubUsername with your actual GitHub username.</p>


<p>Change into the project directory:</p>
<pre><code>cd Movie-Player</code></pre>

<p>Compile the Program:  Ensure you have g++ installed on your system. If not, install it using your package manager. Use the provided makefile to compile the project</p>
<pre><code>make all</code></pre>
<p>This will compile all the necessary files and create the executable proj5 and the test executable qtest.</p>


<p>Run the Movie-Player. After compiling, you can run the main program using the following command:</p>
<pre><code>./proj5</code></pre>
<p>This will start the movie player, where you will be presented with a menu to interact with the movie catalog and playlist.</p>


<p>Run the qtests. To ensure the Queue class functions correctly, you can run the tests:
</p>
<pre><code>./qtest</code></pre>
<p>This will execute the tests defined in queue_test.cpp and help verify the correctness of the Queue implementation.</p>

<!-- CREDITS -->
<h2 id="credits"> :scroll: Credits</h2>

Dua Abdullah 


[![GitHub Badge](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Dua974)
