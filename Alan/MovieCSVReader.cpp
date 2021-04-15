#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>

#include "MovieCSVReader.h"


void MovieCSVReader::read() {
    //readfile
    std::fstream file1;
//    file1.open("/Users/alanchuang/Desktop/codingAssignment/CSC340GroupProject/Alan/tmdb_5000_movies.csv");
    file1.open("./tmdb_5000_movies.csv");

    std::fstream file2;
//    file2.open("/Users/alanchuang/Desktop/codingAssignment/CSC340GroupProject/Alan/tmdb_5000_credits.csv");
    file2.open("./tmdb_5000_credits.csv");

    std::string line1;
    std::string line2;

    while (getline(file1, line1, '\n')) {

        getline(file2, line2, '\n');

        std::string data;
        bool isTitleLine = line1.find("budget", 0) == 0;
        if (isTitleLine) continue;

        try {

            Movie movie;

            // Get all actors
            std::string actorStr = line2.substr(line2.find('[', 0), line2.find(']', 0) - line2.find('[', 0));

            std::vector<std::string> actors;
            int found = actorStr.find(R"(""name"": "")");
            while (found!=std::string::npos) {
                std::string actor = actorStr.substr(found +12, actorStr.find("\"", found+12) - found -12);
                actors.push_back(actor);
                found = actorStr.find(R"(""name"": "")", found + 1);
            }

            movie.setActors(actors);

            // Get all director
            int iDirector = line2.find(R"(""job"": ""Director"")", 0) + 35;
            std::string director = line2.substr(iDirector, line2.find("\"", iDirector) - iDirector);

            movie.setDirector(director);

            // Get all genres
            std::string genreLine = line1.substr(line1.find(R"("[{""id"":)"),
                                                 line1.find("]\"") - line1.find(R"("[{""id"":)"));

            std::istringstream tempLine(genreLine);
            std::vector<std::string> genreMovie;

            while (getline(tempLine, data, '}')) {
                std::string genre = data.substr(data.find("name", 0) + 10,
                                                data.length() - 2 - data.find("name", 0) - 10);
                genres.emplace(genre);  //string 轉換成數字
                genreMovie.push_back(genre);

            }
            movie.setGenres(genreMovie);


            // Get all company names
            std::string companyLine = line1.substr(line1.find(R"("[{""name"": "")"),
                                                   line1.find(',', line1.find(R"("[{""name"": "")")) - 2 -
                                                   line1.find(R"("[{""name"": "")"));

            std::string companyName = companyLine.substr(15, companyLine.length());
            movie.setCompany(companyName);


            // Get all revenues
            std::string revenueLine = line1.substr(nthSubstr(4, line1, "}]\""),
                                                   line1.length() - nthSubstr(4, line1, "}]\""));
            std::string revenueStr = revenueLine.substr(nthSubstr(2, revenueLine, ",") + 1,
                                                        nthSubstr(3, revenueLine, ",") -
                                                        nthSubstr(2, revenueLine, ",") - 1);
            movie.setRevenue(stol(revenueStr));

            // Get all titles
            std::string titleLine = line1.substr(nthSubstr(5, line1, "}]\""),
                                                 line1.length() - nthSubstr(5, line1, "}]\""));
            std::string title = titleLine.substr(nthSubstr(3, titleLine, ",") + 1,
                                                 nthSubstr(4, titleLine, ",") -
                                                 nthSubstr(3, titleLine, ",") - 1);
            movie.setTitle(title);
//            Movie movie2(title, companyName, director, stol(revenueStr), actors, genreMovie);
            movies.push_back(movie);

        } catch (std::exception &message) {
//            std::cout << message.what() << std::endl;
        }

    }

    file1.close();
    file2.close();
}

int MovieCSVReader::nthSubstr(int n, const std::string &s, const std::string &p) {
    std::string::size_type i = s.find(p);     // Find the first occurrence

    int j;
    for (j = 1; j < n && i != std::string::npos; ++j)
        i = s.find(p, i + 1); // Find the next occurrence

    if (j == n)
        return (i);
    else
        return (-1);
}

std::vector<Movie> MovieCSVReader::getMovies() {
    return movies;
}

std::vector<std::string> MovieCSVReader::getGenres() {
    std::vector<std::string> v(genres.begin(), genres.end());
    return v;
}

