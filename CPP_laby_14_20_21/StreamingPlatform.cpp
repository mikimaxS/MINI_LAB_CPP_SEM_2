#include <algorithm>
#include <map>
#include <vector>
#include <iterator>

#include "StreamingPlatform.hpp"

void StreamingPlatform::ProcessLogin(std::string& login)
{
    std::replace_if(login.begin(), login.end(), [](const char& c)
    {
        if ('0' <= c && c <= '9' || 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z')
        {
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

//std::list<const Movie *> StreamingPlatform::GetRecommendedMovies(const User& user, int matchesCount) const
//{
//    class comp
//    {
//    public:
//        bool operator()(const Movie *m1, const Movie *m2) const
//        {
//            if ((*m1).GetRating() < (*m2).GetRating())
//            {
//                return true;
//            }
//            return false;
//        }
//    };
//
//    std::set<const Movie *, comp> set_of_recomendations;
//
//    for_each(this->users.begin(), this->users.end(),
//             [matchesCount, &user, &set_of_recomendations](const std::pair<std::string, User>& u)
//             {
//                 std::vector<const Movie *> tmp;
//
//                 std::set_intersection(user.GetWatchedMovies().begin(), user.GetWatchedMovies().end(),
//                                       u.second.GetWatchedMovies().begin(), u.second.GetWatchedMovies().end(),
//                                       tmp.begin());
//
////                 [](const Movie *m1, const Movie *m2) -> bool
////                 {
////                     if ((*m1).title < (*m2).title)
////                     {
////                         return true;
////                     }
////                     return false;
////                 }
//                 for_each(tmp.begin(), tmp.end(), [](const Movie *m)
//                 {
//                     std::cout << m->title << " ";
//                 });
//                 std::cout << "********" << std::endl;
//
//                 if (tmp.size() >= matchesCount)
//                 {
//                     std::list<const Movie *> tmp_recom;
//                     // coppies the elements from the sorted range [first1,last1) which are not found in [first2, last2)
//                     std::set_difference(u.second.GetWatchedMovies().begin(), u.second.GetWatchedMovies().end(),
//                                         user.GetWatchedMovies().begin(), user.GetWatchedMovies().end(),
//                                         tmp_recom.begin());
//
//                     for_each(tmp_recom.begin(), tmp_recom.end(), [&set_of_recomendations](const Movie *m)
//                     {
//                         set_of_recomendations.insert(m);
//                     });
//                 }
//             });
//
//    std::list<const Movie *> list_of_movies;
//    for_each(set_of_recomendations.begin(), set_of_recomendations.end(), [&list_of_movies](const Movie *m)
//    {
//        list_of_movies.push_back(m);
//    });
//
//    return list_of_movies;
//}

std::list<const Movie *> StreamingPlatform::GetRecommendedMovies(const User& user, int matchesCount) const
{
    std::set<const Movie *> set_of_movies;

    for_each(this->users.begin(), this->users.end(),
             [matchesCount, &set_of_movies, &user](const std::pair<std::string, User> pair_s_u)
             {
                 std::list<const Movie *> intersection;

                 auto list_1 = user.GetWatchedMovies();
                 auto list_2 = pair_s_u.second.GetWatchedMovies();

                 std::set_intersection(list_1.begin(), list_1.end(), list_2.begin(), list_2.end(),
                                       std::back_inserter(intersection));

//                 for_each(intersection.begin(), intersection.end(), [](const Movie *m)
//                 {
//                     std::cout << *m << "**** ";
//                 });

                 if (intersection.size() >= matchesCount)
                 {
                     std::list<const Movie *> difference;
                     std::set_difference(list_2.begin(), list_2.end(), list_1.begin(), list_1.end(),
                                         std::back_inserter(difference));

                     for_each(difference.begin(), difference.end(),
                              [&set_of_movies](const Movie *m)
                              {
                                  set_of_movies.insert(m);
                              });
                 }
             });


    std::list<const Movie *> recom_movies;
    for_each(set_of_movies.begin(), set_of_movies.end(), [&recom_movies](const Movie *m)
    {
        recom_movies.push_back(m);
    });

    return recom_movies;
}