#pragma once
#include <set>

#include <map>
#include <list>
#include <vector>

#include "User.hpp"
#include "Movie.hpp"

class StreamingPlatform
{
private:
    // Etap 1: Dodaj std::set z filmami sortowanymi wg. kolejnosci: tytul, rezyser, rok wydania
    class comp
    {
    public:
        bool operator()(const Movie& b, const Movie& a) const
        {
            if (a.title > b.title)
            {
                return true;
            }
            else if (a.title == b.title)
            {
                if (a.director > b.director)
                {
                    return true;
                }
                else if (a.director == b.director)
                {
                    if (a.releaseYear > b.releaseYear)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    };

    std::set<Movie, comp> movies;

    std::map<std::string, User> users;

    static void ProcessLogin(std::string& login);

public:
//	// Etap 1	
    bool AddMovie(const Movie& movie);
	void PrintMovies(std::ostream& out) const;


//	// Etap 2
	int CountMoviesInYears(int startYear, int endYear) const;
	std::map<std::string, std::vector<const Movie*>> GetMoviesByCategories() const;


    User *AddUser(std::string login, std::string firstName, std::string lastName);
    User *GetUser(std::string login);
    void PrintUsers(std::ostream& out) const;


//	// Etap 6
	std::list<const Movie*> GetRecommendedMovies(const User& user, int matchesCount) const;
};
