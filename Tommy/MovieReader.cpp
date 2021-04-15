#include "MovieReader.h"

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

vector<Movie> MovieReader::getMovies()
{
    return movies;
}

vector<string> MovieReader::getGenres()
{
    return genres;
}

MovieReader::MovieReader()
{
    /*
        1. create hashmap for movies hashset for genres
        2. read file one and populate hashmap and hashset for genres
        3. read file two and populate hashmap and hashset for genres
        4. store hashmap values in movies, hashset values in genres
        */

    std::unordered_map<string, Movie> movieMap;
    std::unordered_set<string> genreSet;

    readFile1(movieMap, genreSet);
    readFile2(movieMap);

    // get all values from movieMap and save to movies
    for (unordered_map<string, Movie>::iterator i = movieMap.begin(); i != movieMap.end(); i++)
    {
        movies.push_back(i->second);
    }
    // convert genreSet to a vector and save to genres
    for (unordered_set<string>::iterator i = genreSet.begin(); i != genreSet.end(); i++)
    {
        genres.push_back(*i);
    }
}

void MovieReader::readFile1(unordered_map<string, Movie> movieMap, unordered_set<string> genreSet)
{
    ifstream inFS;
    inFS.open("tmdb_5000_movies.csv");

    if (!inFS.is_open())
    {
        cout << "could not open file tmdb_5000_movies.csv." << endl;
    }

    string temp;
    getline(inFS, temp);
    string line;
    getline(inFS,line);
    int count = 0;
    while (!inFS.fail())
    {
        cout << count << endl;
        line.erase(remove(line.begin(), line.end(), '\"'), line.end());
        count++;
        if (count == 5000){
            break;
        }
        //strip budget
        string delimiter = ",";
        int position = line.find(delimiter);
        line.erase(0, position + delimiter.length());

        //strip all genres into 1 string
        string endGenre = "]";
        int pos = line.find(endGenre);
        string unformattedGenres = line.substr(0, pos);
        while (unformattedGenres.length() != 1) // empty json threw an error ***
        {
            //this is to collect all of the genres by demiliting from name to the }
            delimiter = "name: ";
            unformattedGenres = unformattedGenres.substr(unformattedGenres.find(delimiter) + 6, unformattedGenres.length());
            delimiter = "}";
            string genre1 = unformattedGenres.substr(0, unformattedGenres.find(delimiter));
            //this puts it into the genre unordered map
            genreSet.insert(genre1);
            //cout << genre1 << endl;

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
        line = line.substr(pos, line.length());

        //grab id
        delimiter = ",";
        
        line = line.substr(line.find(delimiter) + 1, line.length());
        line = line.substr(line.find(delimiter) + 1, line.length());
        string movieId = line.substr(0, line.find(delimiter));
        //
        //cout << movieId << endl;
    
        line = line.substr(line.find(delimiter) + 1, line.length());

        //find original_title
        delimiter = "]";
        line = line.substr(line.find(delimiter) + 1, line.length());
        delimiter = ",";
        line = line.substr(line.find(delimiter) + 1, line.length());
        line = line.substr(line.find(delimiter) + 1, line.length());
        string original_title;
        if (line[0] == ','){
            original_title = "no title";
            //cout << "not hit"<< endl;
        }else{
        //cout << "hit" << endl;
        //cout << line << endl;
        original_title = line.substr(0, line.find(delimiter));
        }
        //
        original_title = line.substr(0, line.find(delimiter));

        //cout << original_title << endl;

        //find company name
        delimiter = "[";
        line = line.substr(line.find(delimiter) + 1, line.length());
        delimiter = ",";
        line = line.substr(7, line.length());
        delimiter = ",";
        string company = line.substr(0, line.find(delimiter));
        delimiter = "]";
        line = line.substr(line.find(delimiter) + 1, line.length());

        //find revenue
        line = line.substr(line.find(delimiter) + 2, line.length());
        delimiter = ',';
        line = line.substr(line.find(delimiter) + 1, line.length());
        string revenue = line.substr(0, line.find(delimiter));
        stringstream integer2(revenue);
        int answer = 0;
        integer2 >> answer;
        

        //I did not implement adding actors
        vector<string> actors1;


        Movie read1 = Movie(original_title, company, " ", answer, actors1, genres);
        // could not solve Undefined symbols for architecture x86_64:
        //    std::unordered_map<string, Movie> movieMap;

        
        //ump.insert({ 20, 130 });
        //movieMap.insert({movieId,read1});

        //     movieMap.insert(make_pair(movieId, read1));
        //mymap["Bakery"]="Barbara";
        movieMap[movieId]=read1;
        Movie temp_movie = movieMap[movieId];
        //cout<< movieMap[movieId]<<endl;
        std::string temp_title = read1.GetTitle();
        cout << "Title: "<<temp_title << endl;
        cout << "company: " << read1.GetCompany() << endl;
        cout << "revenue: "<< read1.GetRevenue() << endl;
        getline(inFS,line);

    }

    if (!inFS.eof())
    {
        cout << "Input failure before reaching end of file." << endl;
    }

    inFS.close();
    
}

void MovieReader::readFile2(unordered_map<string, Movie> movieMap)
{
    ifstream inFS;
    inFS.open("tmdb_5000_credits.csv");

    if (!inFS.is_open())
    {
        cout << "could not open file tmdb_5000_credits.csv." << endl;
    }

    string temp;
    getline(inFS, temp);

    while (!inFS.fail()){
        string line;
        getline(inFS,line);

        //strip all the quotation marks
        line.erase(remove( line.begin(), line.end(), '\"' ), line.end());

        // grab movie id
        string delimiter = ",";
        string id = line.substr(0,line.find(delimiter));
        stringstream integer(id);
        int idOfMovieGenre = 0;
        integer >> idOfMovieGenre;
        cout << "id " << idOfMovieGenre << endl;

        //find director
        delimiter = "Director,";
        int temp1 = line.find(delimiter);
        if (temp1 != -1){
        line = line.substr(temp1, line.length());
        }
        else{
            cout <<"cant find string"<<endl;
            cout << line <<endl;

        }
        delimiter = "}";
        line = line.substr(0,line.find(delimiter));
        delimiter = ": ";
        line = line.substr(line.find(delimiter)+ 2, line.length());
        
        string director = line.substr(0, line.length());
        
        cout << "director" << director << endl;
    }
}


int main() {
    MovieReader movie1;
    movie1.readFile2(movie1.movieMap);
}