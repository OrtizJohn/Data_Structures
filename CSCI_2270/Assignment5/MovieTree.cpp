#include "MovieTree.hpp"
#include <iostream>

using namespace std;

MovieTree::MovieTree(){
  root = 0;
}
MovieTree::~MovieTree(){}
MovieNode *MovieTree::search(string title){
  if(root == NULL){
    return NULL;
  }
  else{
    MovieNode* tmp = root;
    while(tmp != NULL){
      if(tmp->title == title){
        return tmp;
      }
      else if(title< tmp->title){
        tmp = tmp->leftChild;
      }
      else{
        tmp = tmp->rightChild;
      }

    }

  }
}

void MovieTree::findMovie(string title){
  MovieNode *tmp = search(title);
  if(tmp==NULL){
    cout<< "Movie not found."<<endl;
    return;
  }
  cout << "Movie Info:" << endl;
  cout << "==================" << endl;
  cout << "Ranking:" << tmp->ranking << endl;
  cout << "Title  :" << tmp->title << endl;
  cout << "Year   :" << tmp->year << endl;
  cout << "rating :" << tmp->rating << endl;
}
void MovieTree::addMovieNode(int ranking, string title, int year, float rating){

  MovieNode *tmp = new MovieNode(ranking,title,year,rating);
  //Node *tmp = new Node(val);


  if (root == NULL) {
    /* tree is empty */
    /* new root will point to tmp now */
    root = tmp;
    return;
  }
  else {
    MovieNode* curr = root;
    MovieNode* prev = NULL;
    while (curr != NULL) {
      if (title < curr->title) {
        /* We need to insert to the left of this node */
        prev = curr;
        curr = curr->leftChild;
      }
      else {
        /* We need to insert to the right of this node */
        prev = curr;
        curr = curr->rightChild;
      }
    }
    //  curr is pointing to NULL
    // prev is pointing to the parent of tmp

    if (title < prev->title) {
        prev->leftChild = tmp;
    }
    else {
        prev->rightChild = tmp;
    }
    return;
  }
}

void inOrder(MovieNode * node){
  if(node == NULL){
    return;
  }
  inOrder(node->leftChild);
  cout << "Movie: " << node->title << " " << node->rating << endl;
  inOrder(node->rightChild);
}
void preOrder(MovieNode *node,float rating,int year){
  if(node ==NULL){
    return;
  }
  if((node->rating >= rating) && (node->year>=year)){
    cout << node->title << "(" << node->year << ") " << node->rating << endl;
  }
  preOrder(node->leftChild,rating,year);
  preOrder(node->rightChild,rating,year);
}

void MovieTree::printMovieInventory(){
  inOrder(root);
}

void MovieTree::queryMovies(float rating, int year){
  cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
  preOrder(root,rating,year);

}
int Count(MovieNode *node){
  if(node ==NULL){
    return 0;
  }
  else{
    return Count(node->leftChild) + Count(node->rightChild) + 1;
  }


}
float Sum(MovieNode * node){
  if(node == NULL){
    return 0;
  }
  return (node->rating + Sum(node->leftChild) + Sum(node->rightChild));
}

void MovieTree::averageRating(){
  float average = 0.0;
  // cout<< "count: " << Count(root);
  // cout << "sum: " << Sum(root);
  if(root ==NULL){
    cout << "Average rating:" << average << endl;
    return;
  }
  average = (Sum(root)/Count(root));
  cout << "Average rating:" << average << endl;

}
