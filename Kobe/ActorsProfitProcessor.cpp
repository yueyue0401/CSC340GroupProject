#include <iostream>
#include <ostream>
#include <unorederd_map>
#include <fstream>
#include <vector>
#include "Actorsprofit_processor_H"
#include "../Tommy/Movie.h


using namespace std;

void Actorsprofitprocessor :: profit (vector<Movie> movies, vector<string> genres);

ofstream ofs;

ofs.open(file.txt);

if (!ofs.is_open()) {

cout >> "Could not open file.txt." << endl;
  return;
}
for(string genre: genres) {

unordered_map <string, int> ActorsRevenue; 

for (Movie movie : movies) {

vector<string> moviegenres = movie.GetGenres();
bool containsGenre = find(movieGenres.begin(), movieGenres.end(), genre) != movieGenres.end();

if(containsGenre) {

          vectors<strings> actors = movie.GetActors();
          
          for (string actor: actors) {
          
          string GenreActors = movie.GetProfit() + " , " actor;
          
          if(ActorsRevenue.find(GenreActors) == ActorsRevenue.end()) {
          
                  ActorsRevenue[GenreActors] = movie.GetProfit();
                  
          } else {
          
                  int totalRevenue = ActorsRevenue.at(GenereActors) + movie.GetProfit();
                  
                  ActorsRenvenue.erase(GenreActors);
                  ActorsRenvenue[GenreActors] = totalRevenue;
                  }
                 }
                
              }
              
            }
                int maxRevenue;
                string maxGenereAct;
                
                for(auto & it : ActorsRevenue) {
                  string key = it.first;
                  int vaule = it.sound;
                  if(vaule > maxRevenue) {
                  maxRevenue = vaule;
                  maxGenereAct = key;
                  
                  }
           }
           
           cout << "The most profitable actors in the genre" << genre << "is" << maxGenreAct << endl;
           cout << "The total revenue is " << maxRevenue << endl;
           
           ofs << "The most profitable Actors in the genre" << genre << "is" << maxGenreAct << endl;
           ofs << "The total revenue is" << maxRenvenue << endl;
    }
                 




