//
// Created by 莊正煜 on 4/15/21.
//

#ifndef CSC340GROUPPROJECT_MOVIECSVREADER_H
#define CSC340GROUPPROJECT_MOVIECSVREADER_H

#include <set>
#include <Movie.h>

class MovieCSVReader {
public:
    void read();
    std::vector<Movie> getMovies();
    std::vector<std::string> getGenres();
private:
    std::vector<Movie> movies;
    std::set<std::string> genres;
    static int nthSubstr(int n, const std::string& s, const std::string& p);
};


#endif //CSC340GROUPPROJECT_MOVIECSVREADER_H
