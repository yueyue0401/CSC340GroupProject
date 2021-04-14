#ifndef COMPANY_PROCESSOR_H
#define COMPANY_PROCESSOR_H

#include <vector>
#include "../Tommy/Movie.h"
using namespace std;

class CompanyProcessor
{
public:
    static void process(const vector<Movie>& movies, const vector<string>& genres);

private:

};

#endif