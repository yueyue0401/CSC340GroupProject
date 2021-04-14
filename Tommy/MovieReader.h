#include "Movie.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class MovieReader {
    public:
        vector<Movie> getMovies();
        vector<string> getGenres();
        MovieReader();
        void readFile1(unordered_map<string, Movie> movieMap, unordered_set<string> genreSet);
        void readFile2(unordered_map<string, Movie> movieMap);
        /*
        1. create hashmap for movies hashset for genres
        2. read file one and populate hashmap and hashset for genres
        3. read file two and populate hashmap and hashset for genres
        4. store hashmap values in movies, hashset values in genres
        */
    private:
        unordered_map<string, Movie> movieMap;
        unordered_set<string> genreSet;
        vector<Movie> movies;
        vector<string> genres;


};

        // MovieReader reader = new MovieReader();
        // reader.populateData();
        // Movies movies = reader.getMovies();
