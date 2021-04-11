#ifndef Movie_H
#define Movie_H

#include <string>

class Movie{
    public:
        void setData(
            std::string theTitle,
            std::string theCompany,
            std::string theDirector,
            int theRevenue,
            std::vector<std::string> &theActors,
            std::vector<std::string> &theGenres);
        void setTitle(std::string title);
        std::string GetTitle() const;
        std::string GetCompany() const;
        std::string GetDirector() const;
        int GetRevenue() const;
        std::vector<std::string> GetActors();
        std::vector<std::string> GetGenres();

    
    private:
        std::string title;
        std::string company;
        std::string director;
        int revenue;
        std::vector<std::string> *actors;
        std::vector<std::string> *genres;
        
};
#endif