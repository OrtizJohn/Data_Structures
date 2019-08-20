#include "MovieTree.hpp"
#include <iostream>
#include <fstream>


using namespace std;


void printMenu(){
  cout << "======Main Menu======" << endl;
  cout << "1. Print the inventory" << endl;
  cout << "2. Delete a movie" << endl;
  cout << "3. Quit" << endl;
}

int main(int argc, char* argv[]){
  MovieTree movies;
  ifstream inFile(argv[1]);
  if(inFile.fail()){
    std::cout<< "Failed to open the file." <<std::endl;

  }
  else{
    string line = "";
    //gets number of lines
    int numLines=0;
    while(getline(inFile,line)){
      if(line!=""){
        numLines++;
      }
    }

    inFile.clear();
    inFile.seekg(0, std::ios::beg);

    string ranking;
    string title;
    string year;
    string rating;

    int ranking1;

    int year1;
    float rating1;

    for(int i=0;i<numLines;i++){

      getline(inFile,ranking,',');
      ranking1 = stoi(ranking);

      getline(inFile,title,',');

      getline(inFile,year,',');
      year1 = stoi(year);

      getline(inFile,rating,'\n');
      rating1 = stof(rating);

      movies.addMovie(ranking1,title,year1,rating1);


    }

  }
  bool go = true;

  while(go){
    printMenu();
    string ans="";
    getline(cin,ans);
    if(stoi(ans)==1){
      movies.printMovieInventory();
		}
		else if(stoi(ans) == 2){
      string title;
      cout << "Enter a movie title:" << endl;
      getline(cin,title);
      movies.deleteMovie(title);
		}
		else if(stoi(ans)==3){
      cout << "Goodbye!" << endl;
      go = false;
    }

  }
  // movies.addMovie(6,"Pulp Fiction",1994,8.9);
  // movies.addMovie(55,"PCasablanca",1942,8.5);
  // movies.addMovie(55,"PwvCasablanca",1942,8.5);
  // movies.addMovie(1,"Shawshank Redemption",1994,9.3);
  // movies.addMovie(50,"Apocalypse Now",1979,8.5);
  // movies.addMovie(11,"Fight Club",1999,8.8);
  // movies.addMovie(49,"Raiders of the Lost Ark",1981,8.5);
  //
  // movies.printMovieInventory();
  //
  // movies.deleteMovie("Pulp Fiction");
  // movies.deleteMovie("PCasablanca");
  // movies.deleteMovie("PwvCasablanca");
  // movies.deleteMovie("Shawshank Redemption");
  // movies.deleteMovie("Apocalypse Now");
  // movies.deleteMovie("Fight Club");
  // movies.deleteMovie("Raiders of the Lost Ark");
  //
  // cout<<endl;
  // movies.printMovieInventory();
}
