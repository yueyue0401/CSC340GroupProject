#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

class Movie {
public:
    Movie();

    Movie(
            std::string theTitle,
            std::string theCompany,
            std::string theDirector,
            long theRevenue,
            std::vector<std::string> theActors,
            std::vector<std::string> theGenres
    );

    void setTitle(std::string t) { title = t; };

    void setCompany(std::string c) { company = c; };

    void setDirector(std::string d) { director = d; };

    void setRevenue(long r) { revenue = r; };

    void setActors(std::vector<std::string> a) { actors = a; };

    void setGenres(std::vector<std::string> g) {
        genres = g;
    };

    std::string GetTitle();

    std::string GetCompany();

    std::string GetDirector();

    int GetRevenue();

    std::vector<std::string> GetActors();

    std::vector<std::string> GetGenres();



private:
    std::string title;
    std::string company;
    std::string director;
    long revenue;
    std::vector<std::string> actors;
    std::vector<std::string> genres;

};

#endif