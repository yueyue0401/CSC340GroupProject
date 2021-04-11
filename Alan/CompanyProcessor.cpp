#include <iostream>
#include <ostream>
#include <unordered_map>
#include <fstream>

#include "CompanyProcessor.h"
#include "../Tommy/Movie.h"

using namespace std;

/**
 * Get the most profitable companies in genre, and then print and output them as a file.
 * @param movies
 * @param genres
 */
void CompanyProcessor::process(vector<Movie> movies, vector<string> genres) {

    ofstream ofs;
    ofs.open("TTTTTT.txt");

    if (!ofs.is_open()) {
        cout << "Could not open file myoutfile.txt." << endl;
        return;
    }

    for (string genre:genres) {
        unordered_map<string, int> companyTotalRevenue;

        // foreach movies in the certain genre and sum all revenue and then store in map.
        for (Movie movie: movies) {
            vector<string> movieGenres = movie.GetGenres();
            bool containsGenre = find(movieGenres.begin(), movieGenres.end(), genre) != movieGenres.end();

            // check the movie is the certain genre.
            if (containsGenre) {

                // if map exists the company then get the revenue and sum. Or insert revenue directly.
                if (companyTotalRevenue.find(movie.GetCompany()) == companyTotalRevenue.end()) {
                    companyTotalRevenue.insert({movie.GetCompany(), movie.GetRevenue()});

                } else {
                    int totalRevenue = companyTotalRevenue.at(movie.GetCompany()) + movie.GetRevenue();
                    companyTotalRevenue.insert({movie.GetCompany(), totalRevenue});
                }
            }
        }

        // find the max revenue in the certain genre, then print and output in a file.
        int maxRevenue = 0;
        string maxCompany;

        for (auto & it : companyTotalRevenue) {
            string key = it.first;
            int value = it.second;
            if (value > maxRevenue) {
                maxRevenue = value;
                maxCompany = key;
            }
        }


        cout << "The most profitable company in the genre " << genre << " is " << maxCompany << endl;
        cout << "The total revenue is " << maxRevenue << endl;

        // TODO output in a file.
        ofs << "The most profitable company in the genre " << genre << " is " << maxCompany << endl;
        ofs << "The total revenue is " << maxRevenue << endl;
    }

    ofs.close();

}
