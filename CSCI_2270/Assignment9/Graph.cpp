#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include "Graph.hpp"

using namespace std;

Graph::Graph(){

}
Graph::~Graph(){

}
void Graph::addVertex(string cityName){
  vertex v1;
  v1.name = cityName;
  vertices.push_back(v1);
}
void Graph::addEdge(string city1, string city2, int distance){
  Edge nEdge;
  nEdge.v = findVertex(city2);
  nEdge.distance = distance;

  vertex *temp = findVertex(city1);

  temp->Edges.push_back(nEdge);
}
void Graph::displayEdges(){ //done?
  for(int i=0; i<vertices.size();i++){
    cout << vertices[i].name << "-->";
    //print each connection from edges vector
    for(int j=0; j<vertices[i].Edges.size();j++){

      cout<< vertices[i].Edges[j].v->name << " (" <<vertices[i].Edges[j].distance << " miles)";
      if(j!=vertices[i].Edges.size()-1){
        cout<< "***";
      }
    }
    cout<< endl;
  }
}

vertex* Graph::findVertex(string name){
  for (int i = 0; i<vertices.size();i++){
    if (vertices[i].name == name ){
      return &vertices[i];
    }
  }
  return NULL;
}
void Graph::setAllVerticesUnvisited(){
  for(int i = 0;i< vertices.size(); i++){
    vertices[i].visited = false;
  }
}


void Graph::printDFT(){
  setAllVerticesUnvisited();
  //vertex temp = vertices.front();
  for(int i = 0; i< vertices.size();i++){
      vertex temp = vertices[i];
      DFT_traversal(&temp);
  }
  //DFT_traversal(&temp);
}

void Graph::DFT_traversal(vertex *v){
    if(v->visited == true) return;
  for(int i=0;i<vertices.size(); i++){
    if(vertices[i].name == v->name){
      vertex *temp = &vertices[i];
      if(temp->visited) return;
      else{
        temp->visited = true;
        cout << temp->name << endl;
        //cout<< temp->visited<<endl;
        vector<Edge> tempEdges = temp->Edges;
        for(int j = 0; j< tempEdges.size(); j++){
          if(tempEdges[j].v->visited ==false){
            DFT_traversal(tempEdges[j].v);
          }
        }
      }
    }
  }
}

void Graph::printBFT(){
  setAllVerticesUnvisited();
  for(int i = 0; i< vertices.size();i++){
      vertex temp = vertices[i];
      //cout << "new call: " <<i<<endl;
      //cout<<endl;
      if(temp.visited==false){
        BFT_traversal(&temp);
      }
      // BFT_traversal(&temp);
  }
  // vertex temp = vertices[0];
  // BFT_traversal(&temp);

}



void Graph::BFT_traversal(vertex *v){
  vertex *temp = findVertex(v->name);
  queue<vertex> q;
  temp->visited = true;
  //cout<< "adding " << temp->name << " to queue"<<endl;
  q.push(*temp);

  while (!q.empty()) {

    vertex v = q.front();
    cout << v.name << endl;
    q.pop();

    for (auto i = v.Edges.begin(); i != v.Edges.end(); i++) {
        vertex *v1 = findVertex(i->v->name);
        //cout << "checking edge if been visited with name: " << v1->name <<  " visited: " <<v1->visited<<endl;
        if (!v1->visited) {
        	v1->visited = true;
          //cout<< "adding " << v1->name << "to queue"<<endl;
        	q.push(*v1);
        }
    }
  }
}
