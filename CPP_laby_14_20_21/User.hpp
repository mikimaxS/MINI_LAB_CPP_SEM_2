#pragma once
#include <set>

#include <map>
#include <list>
#include <string>
#include <iostream>

class Movie;

class User {
private:
	std::string firstName;
	std::string lastName;
	std::list<const Movie*> watchingHistory;
	std::map<const Movie*, int> ratings;

public:
	User(std::string firstName, std::string lastName);

	friend std::ostream& operator << (std::ostream& out, const User& user);

	void Print(std::ostream& out, bool printMovies) const;


	// Etap 3
	void WatchMovie(const Movie& movie);
	std::list<const Movie*> GetWatchedMovies() const;
	void ClearHistory();


//	// Etap 4
	void RateLastMovie(int rating);


//	// Etap 5
//	int CountWatchTimes(const Movie& movie) const;
//	const Movie* GetFavouriteMovie() const;


//	// Etap 6
	std::set<const Movie*> GetWatchedMoviesSet() const;
};
