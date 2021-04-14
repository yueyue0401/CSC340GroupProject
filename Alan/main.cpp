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
    Movie m1, m2, m3, m4, m5, m6;
    m1.setData("Avatar", "Apple", "John", 100, actors, actGenres);
    m2.setData("Iron man", "Marvel", "Alan", 200, actors, actGenres);
    m3.setData("Superman", "Marvel", "Roger", 100, actors, actGenres);
    m4.setData("La la land", "Apple", "Luke", 100, actors, actGenres);
    m5.setData("The earth", "Discovery", "Amy", 345, actors, actGenres);
    m6.setData("Ocean", "Discovery", "Lisa", 134534500, actors, actGenres);
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
