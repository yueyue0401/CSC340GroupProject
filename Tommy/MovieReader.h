#include "Movie.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class MovieReader {
    public:
        vector<Movie> getMovies();
        vector<string> getGenres();
        void populateData();
        /*
        1. create hashmap for movies hashset for genres
        2. read file one and populate hashmap and hashset for genres
        3. read file two and populate hashmap and hashset for genres
        4. store hashmap values in movies, hashset values in genres
        */
    private:
        vector<Movie> movies;
        vector<string> genres;

        void readFile1(unordered_map<int, Movie> movieMap, unordered_set<string> genreSet);
        void readFile2(unordered_map<int, Movie> movieMap);
};

        // MovieReader reader = new MovieReader();
        // reader.populateData();
        // Movies movies = reader.getMovies();
