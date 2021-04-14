//#ifndef MOVIE_H
//define MOVIE_H

#include <string>
#include <vector>

class Movie{
    public:
        Movie(
            std::string theTitle,
            std::string theCompany,  
            std::string theDirector,
            int theRevenue,
            std::vector<std::string> &theActors,
            std::vector<std::string> &theGenres
        );
        void setTitle(std::string title);
        std::string GetTitle();
        std::string GetCompany();  
        std::string GetDirector();
        int GetRevenue();
        std::vector<std::string> GetActors();
        std::vector<std::string> GetGenres();
        void setId(int intId);
        int getId();
        void setDirector(std::string theDirector);

    
    private:
        int intId;
        std::string title;
        std::string company;
        std::string director;
        int revenue;
        std::vector<std::string> *actors;
        std::vector<std::string> *genres;
        
};
//#endif