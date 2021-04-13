#include "MovieReader.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <iostream>
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
    for (unordered_map<int, Movie>::iterator i = movieMap.begin(); i != movieMap.end(); i++){
        movies.push_back(i->second);
    }
    // convert genreSet to a vector and save to genres
    for (unordered_set <string>::iterator i = genreSet.begin(); i != genreSet.end(); i++ ){
        genres.push_back(*i);
    }
}

void MovieReader::readFile1(unordered_map<int, Movie> movieMap, unordered_set<string> genreSet) {
    ifstream inFS;
    inFS.open("tmdb_5000_movies.csv");

    if(!inFS.is_open()){
        cout << "could not open file tmdb_5000_movies.csv." << endl;
    }

    string line;
    getline(inFS, line);

    line.erase(remove( line.begin(), line.end(), '\"' ), line.end());

    //strip revenue
    string delimiter = ",";
    int position = line.find(delimiter);
    line.erase(0,position + delimiter.length());


    //strip all genres into 1 string
    string endGenre = "]";
    int pos = line.find(endGenre);
    string unformattedGenres = line.substr(0,pos);
    while (unformattedGenres.length() != 0)
    {
        //this is to collect all of the genres by demiliting from name to the }
        delimiter = "name: ";
        unformattedGenres = unformattedGenres.substr(unformattedGenres.find(delimiter) + 6, unformattedGenres.length());
        delimiter = "}";
        string genre1 = unformattedGenres.substr(0, unformattedGenres.find(delimiter));
        //this puts it into the genre unordered map
        genres.insert(genre1);

        if (unformattedGenres.length() > genre1.length() + 1)
        {
            unformattedGenres = unformattedGenres.substr(unformattedGenres.find(delimiter) + 6, unformattedGenres.length());
        }
        else
        {
            unformattedGenres = unformattedGenres.substr(0, 0);
            break;
        }
    }
    
    
    
    //line after genres
    line = line.substr(pos,line.length());

    //grab id
    delimiter = ",";
    line = line.substr(line.find(delimiter) + 1,line.length());
    line = line.substr(line.find(delimiter) + 1,line.length());
    string movieId = line.substr(0,line.find(delimiter));
    moviemap[movieId] = new Movie();
    //convert string to int
    stringstream integer(movieId);

    int idOfMovie = 0;
    integer >> idOfMovie;
    line = line.substr(line.find(delimiter) + 1,line.length());

    //find original_title
    delimiter = "]";
    line = line.substr(line.find(delimiter) + 1,line.length());
    delimiter = ",";
    line = line.substr(line.find(delimiter) + 1,line.length());
    line = line.substr(line.find(delimiter) + 1,line.length());
    string original_title = line.substr(0,line.find(delimiter));

    //find company name
    delimiter = "[";
    line = line.substr(line.find(delimiter) + 1,line.length());
    delimiter = ",";
    line = line.substr(7,line.length());
    delimiter = ",";
    string company = line.substr(0,line.find(delimiter));
    delimiter = "]";
    line = line.substr(line.find(delimiter) + 1, line.length());

    //find revenue
    line = line.substr(line.find(delimiter) + 2, line.length());
    delimiter = ',';
    line = line.substr(line.find(delimiter) + 1, line.length());
    string revenue = line.substr(0,line.find(delimiter));






    inFS.close();
}

void MovieReader::readFile2(unordered_map<int, Movie> movieMap) {

}
