#include <iostream>
#include <ostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include "ActorsProfit.h"
#include "../Tommy/Movie.h"


using namespace std;

void ActorsProfitProcessor::process(vector<Movie> movies, vector<string> genres) {

    ofstream ofs;

    ofs.open("file.txt");

    if (!ofs.is_open()) {

        cout << "Could not open file.txt." << endl;
        return;
    }
    for (string genre: genres) {

        unordered_map<string, int> ActorsRevenue;

        for (Movie movie : movies) {

            vector<string> movieGenres = movie.GetGenres();
            bool containsGenre = find(movieGenres.begin(), movieGenres.end(), genre) != movieGenres.end();

            if (containsGenre) {

                vector <string> actors = movie.GetActors();

                for (string actor: actors) {

                    string GenreActors = movie.GetRevenue() + " , " + actor;

                    if (ActorsRevenue.find(GenreActors) == ActorsRevenue.end()) {

                        ActorsRevenue[GenreActors] = movie.GetRevenue();

                    } else {

                        int totalRevenue = ActorsRevenue.at(GenreActors) + movie.GetRevenue();

                        ActorsRevenue.erase(GenreActors);
                        ActorsRevenue[GenreActors] = totalRevenue;
                    }
                }

            }

        }
        int maxRevenue;
        string maxGenreAct;

        for (auto &it : ActorsRevenue) {
            string key = it.first;
            int value = it.second;
            if (value > maxRevenue) {
                maxRevenue = value;
                maxGenreAct = key;

            }
        }

        cout << "The most profitable actors in the genre" << genre << "is" << maxGenreAct << endl;
        cout << "The total revenue is " << maxRevenue << endl;

        ofs << "The most profitable Actors in the genre" << genre << "is" << maxGenreAct << endl;
        ofs << "The total revenue is" << maxRevenue << endl;
    }

}



