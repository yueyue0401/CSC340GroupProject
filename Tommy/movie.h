#ifndef Movie_H
#define Movie_H

#include <string>
using namespace std;

class Movie{
    public:
        void SetTitleCompanyDirectorRevenue(
            string theTitle,
            string theCompany,
            string theDirector,
            int theRevenue);
        string GetTitle() const;
        string GetCompany() const;
        string GetDirector() const;
        int GetRevenue() const;

    
    private:
        string title = "No_Title";
        string company = "No_Company";
        string director = "No_Director";
        int revenue = -1;
        
};
#endif