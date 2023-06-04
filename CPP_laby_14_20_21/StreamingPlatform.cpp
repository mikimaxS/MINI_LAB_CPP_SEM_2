#include <algorithm>
#include <map>
#include <vector>

#include "StreamingPlatform.hpp"

void StreamingPlatform::ProcessLogin(std::string& login)
{
    std::replace_if(login.begin(), login.end(), [](const char& c){
        if('0' <= c && c <= '9' ||'a' <= c && c <= 'z' ||'A' <= c && c <= 'Z'){
            return false;
        }
        return true;
    }, '_');
}

User *StreamingPlatform::AddUser(std::string login, std::string firstName, std::string lastName)
{
    ProcessLogin(login);

    const auto result = this->users.insert(std::make_pair(login, User{firstName, lastName}));
    if (result.second)
    {
        return &result.first->second;
    }
    return nullptr;
}

User *StreamingPlatform::GetUser(std::string login)
{
    ProcessLogin(login);

    auto it = this->users.find(login);
    if (it != this->users.end())
    {
        return &it->second;
    }
    return nullptr;
}

void StreamingPlatform::PrintUsers(std::ostream& out) const
{
    int idx = 0;
    for (const auto& pair: this->users)
    {
        out << ++idx << ": " << pair.first << " - " << pair.second << '\n';
    }
}

bool StreamingPlatform::AddMovie(const Movie& movie)
{
    auto result = movies.insert(movie);
    return result.second;
}

void StreamingPlatform::PrintMovies(std::ostream& out) const
{
    for_each(this->movies.begin(), this->movies.end(), [&out](const Movie& m)
    {
        out << "[" << m.category << "]" << " \"" << m.title << "\" by " << m.director << " (" << m.releaseYear << ")\n";
    });
}

int StreamingPlatform::CountMoviesInYears(int startYear, int endYear) const
{
    return std::count_if(this->movies.begin(), this->movies.end(),
                         [startYear, endYear](const Movie& m)
                         {
                             if (startYear <= m.releaseYear && m.releaseYear <= endYear)
                             {
                                 return true;
                             }
                             return false;
                         });
}

std::map<std::string, std::vector<const Movie *>> StreamingPlatform::GetMoviesByCategories() const
{
    std::map<std::string, std::vector<const Movie *>> m;

//    for_each(this->movies.rbegin(), this->movies.rend(), [&m](const Movie& movie)
    for_each(this->movies.begin(), this->movies.end(), [&m](const Movie& movie)
    {
        m[movie.category].push_back(&movie);
    });

    return m;
}
