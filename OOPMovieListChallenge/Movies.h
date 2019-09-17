#pragma once

#include <vector>
#include "Movie.h"

class Movies
{
private:
	std::vector<Movie>* movieList{ nullptr };

public:
	// Constructor
	Movies();
	// Copy Constructor
	Movies(const Movies& source);
	// Move Constructor
	Movies(Movies&& source) noexcept;

	// Destructor
	~Movies();

	// Methods
	void AddMovie(std::string movieName, Rating movieRating, int timesWatched = 0);
	void WatchedMovie(std::string movieName);
	void DisplayMovies() const;
};

