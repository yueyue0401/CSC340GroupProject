#include "Movie.h"
#include <vector>
#include <string>

void Movie::Movie(
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

std::string Movie::GetTitle() const
{
    return title;
}

std::string Movie::GetCompany() const
{
    return company;
}

std::string Movie::GetDirector() const
{
    return director;
}

int Movie::GetRevenue() const
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

void setId(int intId)
{
    this->intId = intId;
}

int getId(){
    return intId;
}

void setDirector(string theDirector){
    this->theDirector = theDirector;
}
