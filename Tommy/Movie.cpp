#include "Movie.h"
#include <vector>
#include <string>

Movie::Movie(
    std::string theTitle,
    std::string theCompany,
    std::string theDirector,
    long theRevenue,
    std::vector<std::string> theActors,
    std::vector<std::string> theGenres)
{
    title = theTitle;
    company = theCompany;
    director = theDirector;
    revenue = theRevenue;
    actors = theActors;
    genres = theGenres;
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
    return actors;
}

std::vector<std::string> Movie::GetGenres()
{
    return genres;
}

Movie::Movie() {
    // do nothing
}

