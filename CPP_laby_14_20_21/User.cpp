#include <algorithm>

#include "User.hpp"
#include "Movie.hpp"


User::User(std::string firstName, std::string lastName) :
        firstName{firstName}, lastName{lastName} {}

std::ostream& operator<<(std::ostream& out, const User& user)
{
    user.Print(out, true);
    return out;
}


void User::Print(std::ostream& out, bool printMovies) const
{
    out << this->firstName << " " << this->lastName;

    if (printMovies)
    {
        out << ":" << '\n' << "  watched movies:" << '\n';

        int idx = 0;
        for (auto movie: this->watchingHistory)
        {
            out << ++idx << ": ";

            movie->Print(out, true, false);

            // Etap 4: Uzupelnij o wypisywanie oceny filmu
//            if (this->ratings.find(movie)->second != 0)
            if (movie->GetRating() != 0)
                out << " rated " << movie->GetRating() << "/5"; // a conversion to int may be needed

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

void User::RateLastMovie(int rating)
{
    auto movie = *this->watchingHistory.begin();

    if (movie)
    {
        if (this->ratings[movie] == 0)  //new raiting
        {
            this->ratings[movie] = rating;
            movie->AddRating(rating);
        }
        else    // uzytkonik ocenil juz film
        {
            movie->UpdateRating(this->ratings[movie], rating);
            this->ratings[movie] = rating;
        }

        if (rating < 0)
        {
//            std::cout << rating << "***************";
            this->ratings.erase(movie);
            movie->RemoveRating(rating);
        }
    }
}

std::set<const Movie *> User::GetWatchedMoviesSet() const
{
    std::set<const Movie *> s;

    for_each(this->watchingHistory.begin(), this->watchingHistory.end(), [&s](const Movie *m)
    {
        s.insert(m);
    });

    return s;
}
