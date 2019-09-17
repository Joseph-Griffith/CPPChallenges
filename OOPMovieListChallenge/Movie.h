#pragma once
#include <string>

enum Rating
{
	G, PG, PG13, R
};

class Movie
{
private:
	std::string movieName;
	Rating movieRating;
	int numTimesWatched;

public:
	// Constructors
	Movie(std::string movieNameVal, Rating movieRatingVal, int numTimesWatchesVal = 0);

	// Methods
	std::string GetMovieName() const;
	void SetMovieName(std::string movieNameVal);

	Rating GetMovieRating() const;
	void SetMovieRating(Rating movieRatingVal);

	int GetTimesWatched() const;
	void SetTimesWatched(int numTimesWatchesVal);
};

