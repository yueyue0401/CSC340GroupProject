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
    std::cout << "Welcome to Group 15 project " << std::endl;

    std::cout << "Start to read files... " << std::endl;
    MovieCSVReader movieCsvReader;
    movieCsvReader.read();

    std::vector<Movie> movies = movieCsvReader.getMovies();
    std::vector<string> genres = movieCsvReader.getGenres();

    std::cout << "Succeed to read all the data!" << std::endl << std::endl;

    std::cout << std::endl << "Do you want to see the most profitable company in each genres? (Y/N)" << std::endl;
    string ans;
    cin >> ans;

    if (ans == "Y") {
        std::cout << "Start to calculate the most profitable company in each genre... " << std::endl;
        CompanyProcessor::process(movies, genres);
    }

    std::cout << std::endl << "Do you want to see the most profitable director-actor in each genre? (Y/N)" << std::endl;
    cin >> ans;

    if (ans == "Y") {
        std::cout << std::endl << "Start to calculate the most profitable director-actor in each genres..."
                  << std::endl;
        ActorDirectorProcessor adp;
        adp.process(movies, genres);
    }

    std::cout << std::endl << "Thank you for watching" << std::endl;
    std::cout << "　☆ *　. 　☆"<< std::endl;
    std::cout << "　　. ∧＿∧　∩　* ☆"<< std::endl;
    std::cout << "* ☆ ( ・∀・)/ ."<< std::endl;
    std::cout << "　. ⊂　　 ノ* ☆"<< std::endl;
    std::cout << "☆ * (つ ノ .☆"<< std::endl;
    std::cout << "　　 (ノ"<< std::endl;

    std::cout << std::endl << "Group 15 members:" << std::endl;
    std::cout << "Cheng-Yu" << std::endl;
    std::cout << "Jed" << std::endl;
    std::cout << "Kobe" << std::endl;
    std::cout << "Tommy" << std::endl;

    return 0;
}
