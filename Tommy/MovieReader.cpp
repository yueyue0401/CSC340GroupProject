#include "MovieReader.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector<Movie> MovieReader::getMovies() {
    return movies;
}

vector<string> MovieReader::getGenres() {
    return genres;
}

void MovieReader::populateData() {
    /*
        1. create hashmap for movies hashset for genres
        2. read file one and populate hashmap and hashset for genres
        3. read file two and populate hashmap and hashset for genres
        4. store hashmap values in movies, hashset values in genres
        */

    unordered_map<int, Movie> movieMap;
    unordered_set<string> genreSet;

    readFile1(movieMap, genreSet);
    readFile2(movieMap);

    // get all values from movieMap and save to movies
    // convert genreSet to a vector and save to genres
}

void MovieReader::readFile1(unordered_map<int, Movie> movieMap, unordered_set<string> genreSet) {}

void MovieReader::readFile2(unordered_map<int, Movie> movieMap) {}
