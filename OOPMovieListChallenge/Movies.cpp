#include "Movies.h"
#include <iostream>

// Default Constructor
Movies::Movies()
{
	movieList = new std::vector<Movie>;
}
// Copy Constructor
Movies::Movies(const Movies& source)
{
	*movieList = *source.movieList;

	std::cout << "Movies Copy constructor called\n" << std::endl;
}
// Move Constructor
Movies::Movies(Movies&& source) noexcept
	: movieList(source.movieList)
{
	source.movieList = nullptr;

	std::cout << "Movies Move constructor called\n" << std::endl;
}

// Destructor
Movies::~Movies()
{
	delete movieList;

	std::cout << "Movies Destructor called\n" << std::endl;
}

// Adds a movie to the list of movies
void Movies::AddMovie(std::string movieName, Rating movieRating, int timesWatched)
{
	bool movieExists{ false };

	// Check to see if the movie already exists in the list
	for (const auto& movie : *movieList)
	{
		if (movie.GetMovieName() == movieName)
		{
			movieExists = true;
		}
	}

	// Add the movie to the list if it isn't already in the list
	if (!movieExists)
	{
		Movie* movie = new Movie{ movieName, movieRating, timesWatched };

		movieList->push_back(*movie);
		std::cout << movieName << " added\n" << std::endl;

		delete movie;
	}
	else
	{
		std::cout << movieName << " is already in the list\n" << std::endl;
	}
}

// 
void Movies::WatchedMovie(std::string movieName)
{
	bool movieExists{ false };

	for (auto& movie : *movieList)
	{
		if (movie.GetMovieName() == movieName)
		{
			movie.SetTimesWatched(movie.GetTimesWatched() + 1);
			movieExists = true;
		}
	}

	if (movieExists)
	{
		std::cout << movieName << " watch count incremented\n" << std::endl;
	}
	else
	{
		std::cout << movieName << " is not in the list\n" << std::endl;
	}
}

void Movies::DisplayMovies() const
{
	std::cout << "Your list of movies" << std::endl;
	std::cout << "------------------------------------" << std::endl;

	if (movieList->size() == 0)
	{
		std::cout << "Sorry, there are no movies in the list\n" << std::endl;
	}
	else
	{
		for (auto& movie : *movieList)
		{
			std::cout << "Name: " << movie.GetMovieName() << ", ";
			std::cout << "Number of times watched: " << movie.GetTimesWatched() << std::endl;
		}

		std::cout << std::endl;
	}
}
