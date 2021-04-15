#include <iostream>
#include <vector>
#include <string>

#include "./Alan/CompanyProcessor.h"
#include "./Jed/ActorDirectorProcessor.h"
#include "./Tommy/Movie.h"
#include "./Kobe/ActorsProfit.h"


using namespace std;

int main() {
    std::cout << "Welcome to Group 15 project" << std::endl;

    std::vector <Movie> movies;
    std::vector<std::string> actors(1, "Amy");
    std::vector<std::string> actGenres(1, "act");
    std::vector<std::string> docGenres(1, "doc");
    Movie m1("Avatar", "Apple", "John", 100, actors, actGenres);
    Movie m2("Iron man", "Marvel", "Alan", 200, actors, actGenres);
    Movie m3("Superman", "Marvel", "Roger", 100, actors, actGenres);
    Movie m4("La la land", "Apple", "Luke", 100, actors, docGenres);
    Movie m5("The earth", "Discovery", "Amy", 345, actors, docGenres);
    Movie m6("Ocean", "Discovery", "Lisa", 134534500, actors, actGenres);
    movies.push_back(m1);
    movies.push_back(m2);
    movies.push_back(m3);
    movies.push_back(m4);
    movies.push_back(m5);
    movies.push_back(m6);

    string genre;

    while (true) {
        cout << "Enter the genre: (Q to quit)" << endl;
        cin >> genre;
        if (genre == "Q") break;

        vector<string> genres(1, genre);

        CompanyProcessor::process(movies, genres);

        ActorDirectorProcessor adp;
        adp.process(movies, genres);

//        ActorsProfitProcessor app;
//        app.process(movies, genres);

        // Kobe processor
    }

    return 0;
}
