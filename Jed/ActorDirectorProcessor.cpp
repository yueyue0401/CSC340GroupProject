#include <iostream>
#include <ostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include "../Tommy/MovieReader.h"

#include "ActorDirectorProcessor.h"
#include "../Tommy/Movie.h"

using namespace std;



void ActorDirectorProcessor::process(vector<Movie> movies, vector<string> genres) {
    ofstream ofs;
    ofs.open("actorDirectorOutput.txt");

    if (!ofs.is_open()) {
        cout << "Could not open file file.txt." << endl;
        return;
    }

    for (string genre:genres) {
        unordered_map<string, int> directorActorRevenue;
        // foreach movies in the certain genre and sum all revenue and then store in map.
        for (Movie movie: movies) {
            vector<string> movieGenres = movie.GetGenres();
            bool containsGenre = find(movieGenres.begin(), movieGenres.end(), genre) != movieGenres.end();

            // check the movie is the certain genre.
            if (containsGenre) {

                vector<string> actors = movie.GetActors();

                for (string actor:actors) {

                    // concat actor and director into one string
                    string directorActor = movie.GetDirector() + ", " + actor;

                    // if director/actor pair are not already in the map, add it and their combined revenue
                    if (directorActorRevenue.find(directorActor) == directorActorRevenue.end()) {

                        directorActorRevenue[directorActor] = movie.GetRevenue();

                    } else {
                        // if director/actor pair are already in map add revenue to existing value
                        int totalRevenue = directorActorRevenue.at(directorActor) + movie.GetRevenue();

                        // prevent duplicate names
                        directorActorRevenue.erase(directorActor);
                        directorActorRevenue[directorActor] = totalRevenue;

                    }
                }
            }
        }

        int maxRevenue = 0;
        string maxDirAct;

        // find the highest of the total revenues
        for (auto &it : directorActorRevenue) {
            string key = it.first;
            int value = it.second;
            if (value > maxRevenue) {
                maxRevenue = value;
                maxDirAct = key;
            }
        }

        cout << "The most profitable director-actor combination in the genre " << genre << " is " << maxDirAct << endl;
        cout << "The total revenue is " << maxRevenue << endl;

        ofs << "The most profitable director-actor in the genre " << genre << " is " << maxDirAct << endl;
        ofs << "The total revenue is " << maxRevenue << endl;
    }
}
