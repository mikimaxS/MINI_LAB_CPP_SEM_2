#pragma once

#include <string>
#include <iostream>

class Movie {
public:
	std::string title;
	std::string director;
	int releaseYear;
	std::string category;

private:
	mutable int ratingSum = 0;
	mutable int ratingsCount = 0;

public:
	Movie(std::string title, std::string director, int releaseYear, std::string category);

	friend std::ostream& operator << (std::ostream& out, const Movie& movie);

	void Print(std::ostream& out, bool includeCategory, bool includeRating) const;

	void AddRating(int rating) const;
	void RemoveRating(int rating) const;
	void UpdateRating(int oldRating, int newRating) const;
	float GetRating() const;

    friend bool operator< (const Movie& m1, const Movie& m2);
};
