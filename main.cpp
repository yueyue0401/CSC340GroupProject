#include <iostream>
#include <vector>
#include <string>
#include <MovieCSVReader.h>

#include "./Alan/CompanyProcessor.h"
#include "./Jed/ActorDirectorProcessor.h"
#include "./Tommy/Movie.h"
#include "./Kobe/ActorsProfit.h"


using namespace std;

int main() {
    std::cout << "Welcome to Group 15 project" << std::endl;

    MovieCSVReader movieCsvReader;
    movieCsvReader.read();

    std::vector<Movie> movies = movieCsvReader.getMovies();
    std::vector<string> genres = movieCsvReader.getGenres();

//    while (true) {
//        cout << "Enter the genre: (Q to quit)" << endl;
//        cin >> genre;
//        if (genre == "Q") break;

//        vector<string> genres(1, genre);

        CompanyProcessor::process(movies, genres);

        ActorDirectorProcessor adp;
        adp.process(movies, genres);

//        ActorsProfitProcessor app;
//        app.process(movies, genres);

        // Kobe processor
//    }

    return 0;
}
