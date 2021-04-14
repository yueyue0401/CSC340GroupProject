#include <iostream>
#include <vector>
#include <string>

#include "CompanyProcessor.h"
#include "../Tommy/Movie.h"

// using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector <Movie> movies;
    std::vector<std::string> actors(1, "Amy");
    std::vector<std::string> actGenres(1, "act");
    std::vector<std::string> docGenres(1, "doc");
    Movie m1("Avatar", "Apple", "John", 100, actors, actGenres);
    Movie m2("Iron man", "Marvel", "Alan", 200, actors, actGenres);
    Movie m3("Superman", "Marvel", "Roger", 100, actors, actGenres);
    Movie m4("La la land", "Apple", "Luke", 100, actors, actGenres);
    Movie m5("The earth", "Discovery", "Amy", 345, actors, actGenres);
    Movie m6("Ocean", "Discovery", "Lisa", 134534500, actors, actGenres);
    movies.push_back(m1);
    movies.push_back(m2);
    movies.push_back(m3);
    movies.push_back(m4);
    movies.push_back(m5);
    movies.push_back(m6);

    std::vector<std::string> genres;
    genres.emplace_back("act");
    genres.emplace_back("doc");

    CompanyProcessor::process(movies, genres);

    return 0;
}
