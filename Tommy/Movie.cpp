#include "Movie.h"
#include <vector>
#include <string>


Movie::Movie(){
    title = "None";
    company = "None";
    director = "None";
    revenue = 0;

}

Movie::Movie(
    std::string theTitle,
    std::string theCompany,
    std::string theDirector,
    int theRevenue,
    std::vector<std::string> &theActors,
    std::vector<std::string> &theGenres)
{
    title = theTitle;
    company = theCompany;
    director = theDirector;
    revenue = theRevenue;
    actors = &theActors;
    genres = &theGenres;
}

void Movie::setTitle(std::string title)
{
    this->title = title;
}

std::string Movie::GetTitle()
{
    return title;
}

std::string Movie::GetCompany() 
{
    return company;
}

std::string Movie::GetDirector() 
{
    return director;
}

int Movie::GetRevenue()
{
    return revenue;
}

std::vector<std::string> Movie::GetActors()
{
    return *actors;
}

std::vector<std::string> Movie::GetGenres()
{
    return *genres;
}

void Movie::setId(int intId)
{
    this->intId = intId;
}

int Movie::getId(){
    return intId;
}

void Movie::setDirector(std::string theDirector){
    this->director = theDirector;
}


