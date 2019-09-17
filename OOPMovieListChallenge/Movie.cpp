#include "Movie.h"
#include <iostream>

// Overloaded Constructor
Movie::Movie(std::string movieNameVal, Rating movieRatingVal, int numTimesWatchesVal)
	:movieName{ movieNameVal }, movieRating{ movieRatingVal }, numTimesWatched{ numTimesWatchesVal } {}

// Methods
std::string Movie::GetMovieName() const
{
	return movieName;
}

void Movie::SetMovieName(std::string movieNameVal)
{
	movieName = movieNameVal;
}

Rating Movie::GetMovieRating() const
{
	return movieRating;
}

void Movie::SetMovieRating(Rating movieRatingVal)
{
	movieRating = movieRatingVal;
}

int Movie::GetTimesWatched() const
{
	return numTimesWatched;
}

void Movie::SetTimesWatched(int numTimesWatchesVal)
{
	numTimesWatched = numTimesWatchesVal;
}
