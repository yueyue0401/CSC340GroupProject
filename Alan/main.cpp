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
    std::vector<std::string> mGenres(1, "act");
    Movie m;
    m.setData("Avatar", "Apple", "John", 100, actors, mGenres);
    movies.push_back(m);

    std::vector<std::string> genres(1, "act");

    CompanyProcessor cp;
    cp.process(movies, genres);

    return 0;
}
