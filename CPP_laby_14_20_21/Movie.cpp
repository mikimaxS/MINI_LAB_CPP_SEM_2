#include "Movie.hpp"

#include <iomanip>

Movie::Movie(std::string title, std::string director, int releaseYear, std::string category) :
        title{title}, director{director}, category{category}, releaseYear{releaseYear}
{
}

std::ostream& operator<<(std::ostream& out, const Movie& movie)
{
    movie.Print(out, true, true);
    return out;
}

void Movie::Print(std::ostream& out, bool includeCategory, bool includeRating) const
{
    if (includeCategory)
    {
        out << "[" << this->category << "] ";
    }

    out << "\"" << this->title << "\" by " << this->director << " (" << this->releaseYear << ")";

    if (includeRating && this->ratingsCount > 0)
    {
        out << " rated " << std::fixed << std::setprecision(1) << this->GetRating() << "/5.0";
    }
}

void Movie::AddRating(int rating) const
{
    this->ratingSum += rating;
    this->ratingsCount += 1;
}

void Movie::RemoveRating(int rating) const
{
    this->ratingSum -= rating;
    this->ratingsCount -= 1;
}

void Movie::UpdateRating(int oldRating, int newRating) const
{
    this->ratingSum -= oldRating;
    this->ratingSum += newRating;
}

float Movie::GetRating() const
{
    if (this->ratingsCount == 0)
    {
        return 0.0f;
    }
    return static_cast<float>(this->ratingSum) / static_cast<float>(this->ratingsCount);
}

bool operator<(const Movie& m1, const Movie& m2)
{
    if (m1.title > m2.title)
    {
        return true;
    }
    return false;
}
