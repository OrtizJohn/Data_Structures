#include "MovieTree.hpp"
#include <iostream>
#include <fstream>

// you may include more libraries as needed

using namespace std;


void printMenu(){
  cout << "======Main Menu======" << endl;
  cout << "1. Find a movie" << endl;
  cout << "2. Query movies" << endl;
  cout << "3. Print the inventory" << endl;
  cout << "4. Average Rating of movies" << endl;
  cout << "5. Quit" << endl;
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

      movies.addMovieNode(ranking1,title,year1,rating1);


    }

  }
  bool go = true;

  while(go){
    printMenu();
    string ans="";
    getline(cin,ans);
    if(stoi(ans)==1){
      string title;
      cout << "Enter title:" << endl;
      getline(cin,title);
      movies.findMovie(title);
		}
		else if(stoi(ans) == 2){
      string rating;
      string year;
      cout << "Enter minimum rating:" << endl;
      getline(cin,rating);
      cout << "Enter minimum year:" << endl;
      getline(cin,year);
      movies.queryMovies(stof(rating),stoi(year));
		}
		else if(stoi(ans)==3){
      movies.printMovieInventory();
    }
    else if(stoi(ans)==4){
      movies.averageRating();
    }
    else if(stoi(ans)==5){
      cout << "Goodbye!" << endl;
      go = false;
    }
  }
  // movies.addMovieNode(6,"Pulp Fiction",1994,8.9);
  // movies.addMovieNode(55,"Casablanca",1942,8.5);
  // movies.addMovieNode(1,"Shawshank Redemption",1994,9.3);
  // movies.addMovieNode(50,"Apocalypse Now",1979,8.5);
  // movies.addMovieNode(11,"Fight Club",1999,8.8);
  // movies.addMovieNode(49,"Raiders of the Lost Ark",1981,8.5);
  // movies.addMovieNode(4,"The Godfather",1972,9.2);
  // movies.averageRating();

}
