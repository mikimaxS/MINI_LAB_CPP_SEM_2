#include <algorithm>

#include "User.hpp"
#include "Movie.hpp"


User::User(std::string firstName, std::string lastName) :
	firstName{ firstName }, lastName{ lastName } 
{
}

std::ostream& operator << (std::ostream& out, const User& user) {
	user.Print(out, true);
	return out;
}



void User::Print(std::ostream& out, bool printMovies) const {
	out << this->firstName << " " << this->lastName;

	if (printMovies) {
		out << ":" << '\n' << "  watched movies:" << '\n';
		
		int idx = 0;
		for (auto movie : this->watchingHistory) {
			out << ++idx << ": ";

			movie->Print(out, true, false);

			// Etap 4: Uzupe�nij o wypisywanie oceny filmu

			out << '\n';
		}
	}
}

void User::WatchMovie(const Movie& movie)
{
    this->watchingHistory.push_front(&movie);
}

void User::ClearHistory()
{
    this->watchingHistory.clear();
}

std::list<const Movie *> User::GetWatchedMovies() const
{
    auto list(this->watchingHistory);
    std::reverse(list.begin(), list.end());

    return list;
}
