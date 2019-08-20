#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;
string GetCity2(vector<string> cities, int index){
  return cities[index];
}



int main(int argc, char* argv[]){
  Graph g1;
  vector<string> cities;
  //cout << argv[1]<<endl;
  ifstream inFile(argv[1]);
  if(inFile.fail()){
    cout<< "Failed to open the file." <<endl;

  }
  else{
    string line = "";
    int count = 0;
    while (getline(inFile, line)){
      //cout <<line<<endl;
      //cout <<count;
      if(count == 0){
        //cout<<"hi"<<endl;
        istringstream linestream(line);
        string city;
        //cout << "hi"<<endl;
        int count1 =0;
        while(getline(linestream, city, ',')){
          if(count1!=0){
            g1.addVertex(city);
            //cout<< city<<endl;
            cities.push_back(city);
          }
          count1++;
        }

      }

      if(count !=0){
        //cout<<count<<endl;
        //cout << line<<endl;
        //cout<<endl;
        istringstream linestream1(line);
        string city1;
        string city2;
        int count2=0;
        int distance=0;
        while(getline(linestream1, city2, ',')){
          if(count2 ==0){
            city1 = city2;
            //cout <<city1<<endl;
          }
          if(count2 != 0){
            distance = stoi(city2);
            //cout << distance<<" ";
            if(distance>0){
              string connectedCity = GetCity2(cities,count2-1);
              g1.addEdge(city1,connectedCity,distance);
              cout << " ... Reading in " << city1 << " -- " << connectedCity << " -- " <<distance << endl;

            }
          }
          count2++;
        }//cout<<endl;

      }

      count++;
    }

    cout << "------------------------------ " << endl
    << "Breadth First Traversal" << endl
    << "------------------------------" << endl;
    g1.printBFT();
    cout << "------------------------------ " << endl
    << "Depth First Traversal" << endl
    << "------------------------------"<< endl;
    g1.printDFT();
    cout << "------------------------------ " << endl
    << "Display Edges" << endl
    << "------------------------------"<< endl;
    g1.displayEdges();
  }

  // g1.addVertex("San Diego");
  // g1.addVertex("Denver");
  // g1.addVertex("Boulder");
  // g1.addVertex("Mexico");
  // g1.addEdge("San Diego", "Denver", 2);
  // g1.addEdge("Denver", "San Diego", 2);
  // g1.addEdge("Boulder","Mexico",51356);
  // g1.addEdge("Denver", "Mexico", 1);
  // g1.displayEdges();
  // //g1.printDFT();
  // g1.printBFT();
}
