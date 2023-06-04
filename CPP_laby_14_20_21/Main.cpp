#include <iostream>

#include "Movie.hpp"
#include "StreamingPlatform.hpp"

void CheckAddMovie(bool result)
{
    if (result)
    {
        std::cout << "Movie added" << '\n';
    }
    else
    {
        std::cout << "Failed to add movie" << '\n';
    }
}

void CheckAddUser(const User *user)
{
    if (user != nullptr)
    {
        std::cout << "User added: ";
        user->Print(std::cout, false);
        std::cout << '\n';
    }
    else
    {
        std::cout << "Failed to add user" << '\n';
    }
}


int main()
{

    const auto Movies = {
            Movie{"Blue Mile", "Drank Farabont", 1999, "Drama"},
            Movie{"Shashlik Redemption", "Drank Farabont", 1994, "Drama"},
            Movie{"Fortnite Gump", "Randy Zemick", 1994, "Drama"},
            Movie{"Professional Lion", "Buc Lesson", 1994, "Drama"},
            Movie{"Metrix", "Landa Wachowek", 1999, "Sci-Fi"},
            Movie{"Blue People", "Johny Cameraman", 2009, "Sci-Fi"},
            Movie{"Outception", "Kris Nolis", 2010, "Sci-Fi"},
            Movie{"I Am Legendary", "Lrancis Fawrence", 2007, "Sci-Fi"},
            Movie{"The Lord of the Earrings", "Piter Ronaldson", 2001, "Fantasy"},
            Movie{"Midget: Amazing Journey", "Piter Ronaldson", 2012, "Fantasy"},
            Movie{"Jerry Notter and the Wizards' Stone", "Columbus John", 2001, "Fantasy"},
            Movie{"Johny Week", "Martinez Best", 1998, "Fantasy"},
            Movie{"Shrik", "Andy Adamdaughter", 2001, "Comedy"},
            Movie{"The Sobriety", "Phillips Ted", 2009, "Comedy"},
            Movie{"The Falseman Show", "Weter Peir", 1998, "Comedy"},
            Movie{"Alivepool", "Mim Tiller", 2016, "Comedy"}
    };


    std::cout << '\n' << "==================== Etap 1 ====================" << '\n';
    {
        StreamingPlatform testPlatform;

        Movie testMovie1{"The First Movie", "Some director", 2004, "Some category"};
        Movie testMovie2 = testMovie1;
        Movie testMovie3{"The First Movie", "Some director", 1996, "Some category"};
        Movie testMovie4{"The First Movie", "Some other director", 2004, "Some category"};
        Movie testMovie5{"The Second Movie", "Some director", 2004, "Some category"};

        CheckAddMovie(testPlatform.AddMovie(testMovie1));
        CheckAddMovie(testPlatform.AddMovie(testMovie1));
        CheckAddMovie(testPlatform.AddMovie(testMovie2));
        CheckAddMovie(testPlatform.AddMovie(testMovie3));
        CheckAddMovie(testPlatform.AddMovie(testMovie4));
        CheckAddMovie(testPlatform.AddMovie(testMovie5));

        std::cout << '\n';

        std::cout << "Test platform movies:" << '\n';
        testPlatform.PrintMovies(std::cout);

        std::cout << '\n';
    }

    StreamingPlatform streamingPlatform;

    for (const auto& movie: Movies)
    {
        streamingPlatform.AddMovie(movie);
    }

    std::cout << "All movies:" << '\n';
    streamingPlatform.PrintMovies(std::cout);


    std::cout << '\n' << "==================== Etap 2 ====================" << '\n';

    std::cout << '\n';
    std::cout << "There are " << streamingPlatform.CountMoviesInYears(1999, 2008)
              << " movies released between year 1999 and 2008" << '\n';


    auto moviesByCategories = streamingPlatform.GetMoviesByCategories();

    std::cout << '\n';
    std::cout << "Movies by categories:" << '\n';

    for (const auto& pair: moviesByCategories)
    {
        std::cout << "[" << pair.first << "]:" << '\n';
        for (const auto movie: pair.second)
        {
            std::cout << "  ";
            movie->Print(std::cout, false, false);
            std::cout << '\n';
        }
    }




	std::cout << '\n' << "==================== Etap 3 ====================" << '\n';

	auto user1 = streamingPlatform.AddUser("%U?s*e(r 1", "John", "Smith");
	CheckAddUser(user1);

	auto user2 = streamingPlatform.AddUser("_U_s_e_r_1", "Jane", "Doe");
	CheckAddUser(user2);

	auto user3 = streamingPlatform.AddUser("Use^r3", "Aliza", "Forster");
	CheckAddUser(user3);

	auto user4 = streamingPlatform.AddUser("Us}er4", "Tayler", "Bernard");
	CheckAddUser(user4);

	auto user5 = streamingPlatform.AddUser("User+5", "Filip", "Finch");
	CheckAddUser(user5);


	user1->WatchMovie(*moviesByCategories.at("Drama")[0]);
	user1->WatchMovie(*moviesByCategories.at("Comedy")[0]);
	user1->WatchMovie(*moviesByCategories.at("Drama")[3]);
	user1->WatchMovie(*moviesByCategories.at("Drama")[2]);
	user1->WatchMovie(*moviesByCategories.at("Comedy")[3]);
	user1->WatchMovie(*moviesByCategories.at("Drama")[1]);
	user1->WatchMovie(*moviesByCategories.at("Drama")[0]);
	user1->WatchMovie(*moviesByCategories.at("Fantasy")[1]);


	std::cout << '\n';
	std::cout << "All users:" << '\n';
	streamingPlatform.PrintUsers(std::cout);

	const auto user1WatchedMovies = user1->GetWatchedMovies();

	user1->ClearHistory();

	std::cout << '\n';
	std::cout << "All users:" << '\n';
	streamingPlatform.PrintUsers(std::cout);


	std::cout << '\n';
	std::cout << "Watched movies list:" << '\n';
	for (const auto movie : user1WatchedMovies) {
		movie->Print(std::cout, true, false);
		std::cout << '\n';
	}




	std::cout << '\n' << "==================== Etap 4 ====================" << '\n';

	user3->RateLastMovie(5);
	user4->RateLastMovie(-1);


	user5->WatchMovie(*moviesByCategories.at("Drama")[0]);
	user5->RateLastMovie(3);

	user5->WatchMovie(*moviesByCategories.at("Sci-Fi")[2]);
	user5->RateLastMovie(-1);

	user5->WatchMovie(*moviesByCategories.at("Fantasy")[0]);
	user5->RateLastMovie(4);

	user5->WatchMovie(*moviesByCategories.at("Drama")[0]);
	user5->RateLastMovie(-1);

	user5->WatchMovie(*moviesByCategories.at("Comedy")[1]);
	user5->RateLastMovie(5);

	user5->WatchMovie(*moviesByCategories.at("Comedy")[3]);


	user1->WatchMovie(*moviesByCategories.at("Sci-Fi")[3]);

	user1->WatchMovie(*moviesByCategories.at("Drama")[0]);
	user1->RateLastMovie(4);

	user1->WatchMovie(*moviesByCategories.at("Sci-Fi")[2]);
	user1->RateLastMovie(3);

	user1->WatchMovie(*moviesByCategories.at("Fantasy")[2]);
	user1->RateLastMovie(2);

	user1->WatchMovie(*moviesByCategories.at("Sci-Fi")[2]);
	user1->RateLastMovie(4);

	user1->WatchMovie(*moviesByCategories.at("Fantasy")[0]);
	user1->RateLastMovie(1);

	user1->WatchMovie(*moviesByCategories.at("Sci-Fi")[3]);
	user1->RateLastMovie(5);

	user1->WatchMovie(*moviesByCategories.at("Comedy")[1]);
	user1->RateLastMovie(5);


	user3->WatchMovie(*moviesByCategories.at("Sci-Fi")[2]);
	user3->RateLastMovie(4);

	user3->WatchMovie(*moviesByCategories.at("Fantasy")[3]);
	user3->WatchMovie(*moviesByCategories.at("Comedy")[1]);
	user3->RateLastMovie(3);

	user3->WatchMovie(*moviesByCategories.at("Fantasy")[1]);
	user3->RateLastMovie(4);

	user3->WatchMovie(*moviesByCategories.at("Fantasy")[2]);

	user3->WatchMovie(*moviesByCategories.at("Fantasy")[0]);
	user3->RateLastMovie(3);

	user3->WatchMovie(*moviesByCategories.at("Fantasy")[1]);


	std::cout << '\n';
	std::cout << "All users:" << '\n';
	streamingPlatform.PrintUsers(std::cout);

	std::cout << '\n';
	std::cout << "All movies:" << '\n';
	streamingPlatform.PrintMovies(std::cout);




//	std::cout << '\n' << "==================== Etap 5 ====================" << '\n';
//
//	const auto PrintRecommendedMovies = [](const User* user, const std::list<const Movie*>& movies) {
//		std::cout << '\n';
//		std::cout << "Movies recommended for ";
//		user->Print(std::cout, false);
//		std::cout << ":" << '\n';
//		for (const auto movie : movies) {
//			std::cout << *movie << '\n';
//		}
//	};
//
//	const auto recommendedMovies1 = streamingPlatform.GetRecommendedMovies(*user1, 2);
//	PrintRecommendedMovies(user1, recommendedMovies1);
//
//	const auto recommendedMovies3 = streamingPlatform.GetRecommendedMovies(*user3, 4);
//	PrintRecommendedMovies(user3, recommendedMovies3);
//
// 	const auto recommendedMovies4 = streamingPlatform.GetRecommendedMovies(*user4, 0);
//	PrintRecommendedMovies(user4, recommendedMovies4);
//	
//	const auto recommendedMovies5 = streamingPlatform.GetRecommendedMovies(*user5, 4);
//	PrintRecommendedMovies(user5, recommendedMovies5);




    return 0;
}
