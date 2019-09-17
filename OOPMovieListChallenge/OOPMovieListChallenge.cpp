/*
	For this challenge you are to develop the foundation for a program for movie fanatics to keep track of what movies
	they have watched and how many times they watched each movie.

	The program must support the following:

	class Movie - models a movie which includes
		- Movie name
		- Movie rating (G, PG, PG-13, R)
		- Watched - the number of times the movie has been watched

	class Movies - models a collection of movie objects

	Obviously, Movies need to know about Movie since it is a collection of Movie object
	However, our main driver should only interact with the Movie class.

	For example, a simple main should be able to
		- Create a Movies object
		- Ask the Movies object to add a movie by providing the movie name, rating and watched count
		- Ask the Movies object to increment the watched count by 1 for a movie given its name
		- Ask the Movies object to display all of it's movies

	Additionally,
		- If we try to add a movie whose name is already in the movies collection, we should display an error to the user
		- If we try to increment the watched count for a movie whos name is not in the movies collection, we should display an error to the user
*/

#include <iostream>
#include "Movies.h"

int main()
{
	Movies myMovies;

	// Challenge solution test
	myMovies.DisplayMovies();
	myMovies.AddMovie("Big", PG13, 2);
	myMovies.AddMovie("Star Wars", PG, 5);
	myMovies.AddMovie("Cinderella", PG, 7);

	myMovies.DisplayMovies(); // Big, Star Wars, Cinderella

	myMovies.AddMovie("Cinderella", PG, 7); // Already exists
	myMovies.AddMovie("Ice Age", PG, 12);

	myMovies.DisplayMovies(); // Big, Star Wars, Cinderella, Ice Age

	myMovies.WatchedMovie("Big");
	myMovies.WatchedMovie("Ice Age");

	myMovies.DisplayMovies(); // Big and Ice Age watch count incremented by 1

	myMovies.WatchedMovie("XXX"); // XXX not found
}