#include "MovieTree.hpp"
#include <iostream>

using namespace std;

void deleteLL(LLMovieNode* head)
{
    if (head == NULL)
        return;
    deleteLL(head->next);
    delete head;
}
void deleteTree(TreeNode *node)
{
    if (node == NULL) return;


    deleteTree(node->leftChild);
    deleteTree(node->rightChild);



    /*TODO first delete both subtrees */

    /* TODO then delete the node */
    //cout<<"\n Deleting node:"<< node->data;
    deleteLL(node->head);
    delete node;
}

MovieTree::MovieTree(){
  root=NULL;
}
MovieTree::~MovieTree(){
  //call delete function
  deleteTree(root);
}

void inOrder(TreeNode * node){
  if(node == NULL){
    return;
  }
  inOrder(node->leftChild);
  cout << "Movies starting with letter: " << node->titleChar << endl;
  LLMovieNode *temp = node->head;
  while(temp!=NULL){
    cout << " >> " << temp->title << " " << temp->rating << endl;
    temp = temp->next;
  }
  inOrder(node->rightChild);
}
void MovieTree::printMovieInventory(){
  inOrder(root);
}



void MovieTree::addMovie(int ranking, string title, int year, float rating){
  LLMovieNode *nn = new LLMovieNode(ranking,title,year,rating);
  if(root ==NULL){
    //create new TreeNode
    TreeNode *newTreeNode = new TreeNode;
    newTreeNode->titleChar = title[0];
    //add movie Node assuming no former head of movie list(new node)

    if(newTreeNode->head == NULL){
      //if list empty
      //cout<<"Movie List empty making movie head of list..."<<endl;
      nn->next = newTreeNode->head;
      newTreeNode->head = nn;

    }
    //////////////////////////////////////////////////////////////////
    root = newTreeNode;

    //cout<< "Creating new TreeNode with char as: " << newTreeNode->titleChar <<endl;
  }
  else{
    TreeNode* curr = root;
    //cout<< "Root equals: "<< root << endl;
    TreeNode* prev = NULL;
    while (curr != NULL) {
      if(title[0] == curr->titleChar){
        //we dont need to insert new TreeNode
        ///////////////////////////////////////////////////////////////
        //add movieNode
        LLMovieNode *currLL = curr->head;
        LLMovieNode *prevLL = currLL;

        if(nn->title < currLL->title){
          //cout<<"Movie is going before head of the current movie list..." <<endl;
          //movie goes before head of movie list
          nn->next = currLL;
          curr->head = nn;
        }
        else{
          bool go = true;
          while(go){
            if((nn->title < currLL->title)&&(nn->title > prevLL->title)){
              //middle
              //cout<<"Going in the middle of the movie list..." <<endl;
              prevLL->next = nn;
              nn->next = currLL;
              go = false;
            }
            if((nn->title > currLL->title)&& (currLL->next == NULL)){
              //end of list of movies
              //cout << "Goes on the end of the movie list" <<endl;
              currLL->next = nn;
              nn->next = NULL;
              go = false;
            }
            prevLL = currLL;
            currLL = currLL->next;
          }
        }
        ///////////////////////////////////////////////////////////
        //cout<<"Already existing TreeNode... " <<curr->titleChar<<endl;
        return;
      }
      else if (title[0] < curr->titleChar) {
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



    if (title[0] < prev->titleChar) {
      TreeNode *tmp = new TreeNode;
      tmp->titleChar = title[0];

      //add movieNode
      if(tmp->head == NULL){
        //if list empty
        //cout<<"Movie List empty making movie head of list..."<<endl;
        nn->next = tmp->head;
        tmp->head = nn;

      }
    ///////////////////////////////////////////////////////////////////////
      prev->leftChild = tmp;
    }
    else {
      TreeNode *tmp = new TreeNode;
      tmp->titleChar = title[0];

      //add movieNode
      if(tmp->head == NULL){
        //if list empty
        //cout<<"Movie List empty making movie head of list..."<<endl;
        nn->next = tmp->head;
        tmp->head = nn;

      }
      //////////////////////////////////////////////////////
      prev->rightChild = tmp;
    }
    return;
  }


}



/////////////////////////////////////////////////////////////////////

TreeNode *searchTree(string title,TreeNode *root){
  if(root == NULL){
    return NULL;
  }
  else{
    TreeNode* tmp = root;
    while(tmp != NULL){
      if(tmp->titleChar == title[0]){
        return tmp;
      }
      else if(title[0]< tmp->titleChar){
        tmp = tmp->leftChild;
      }
      else{
        tmp = tmp->rightChild;
      }

    }

  }
}


TreeNode* getMinValueNode(TreeNode* currNode){

    if(currNode->leftChild == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->leftChild);
}

TreeNode* deleteNode(TreeNode *currNode, char value)
{

  if(currNode == NULL)
  {
    return NULL;
  }
  else if(value < currNode->titleChar)
  {
    currNode->leftChild = deleteNode(currNode->leftChild, value);
  }
  else if(value > currNode->titleChar)
  {
    currNode->rightChild = deleteNode(currNode->rightChild, value);
  }
  // We found the node with the value
  else
  {

    //TODO Case : No child
    if(currNode->leftChild == NULL && currNode->rightChild == NULL)
    {
      ////////////////////////////////////
      /*
      1.delete current node
      2 make current node  = NULL
      */
      delete currNode;
      currNode = NULL;
      //////////////////////////////////////////
    }
    //TODO Case : Only right child
    else if(currNode->leftChild == NULL)
    {
      /*
      1.create a not temp
      2.make temp = current nodes
      3.shift current node to its right child
      4.delete temp
      */
      TreeNode *temp = currNode;
      currNode = currNode->rightChild;
      delete temp;

    }
    //TODO Case : Only left child
    else if(currNode->rightChild == NULL)
    {
      /*
      1.create a not temp
      2.make temp = current nodes
      3.shift current node to its left child
      4.delete temp
      */
      TreeNode *temp = currNode;
      currNode = currNode->leftChild;
      delete temp;

    }
    //TODO Case: Both left and right child
    else
    {
      /*
      1.create a node main
      2.get the min value of the right subtree and store it in main
      3.replace the key of current node with the key of main
      4.call deleteNOde() as a recursive function into the right subtree of current node to delete the duplicate
      */
      TreeNode *min = getMinValueNode(currNode->rightChild);
      currNode->titleChar = min->titleChar;
      currNode->head = min->head;
      currNode->rightChild = deleteNode(currNode->rightChild, min->titleChar);
      ///Replace with Minimum from right subtree

    }

  }
return currNode;
}



bool searchMovieList(string title, LLMovieNode *head){
  if(head == NULL){
    return false;
  }
  else{
    LLMovieNode *temp = head;
    while(temp!= NULL){
      if(temp->title == title){
        return true;
      }
      temp = temp->next;
    }
  }
  return false;
}
void MovieTree::deleteMovie(string title){
  //if tree empty
  TreeNode *temp = searchTree(title,root);
  if(temp ==NULL){
    cout << "Movie: " << title << " not found, cannot delete." << endl;
    return;
  }
  else{
    //cout<<"Searching Tree Node: " <<temp->titleChar<<endl;
    if(searchMovieList(title,temp->head)){


      LLMovieNode *currLL = temp->head;
      LLMovieNode *prevLL = NULL;

      bool del = false;
      while(currLL!=NULL){
        if((title == currLL->title)&&(prevLL == NULL)){//delete at front of link list
          temp->head = temp->head->next;
          delete currLL;
          del = true;
        }

        else if((title > currLL->title)&& (currLL->next == NULL)){
          //end of list of movies
          //cout << "Goes on the end of the movie list" <<endl;
          prevLL->next = NULL;
          delete currLL;
          del = true;
        }
        prevLL = currLL;
        currLL = currLL->next;
      }
      if(del == false){
        //middle
        //cout<<"Going delete in the middle of the movie list..." <<endl;
        currLL= temp->head;
        prevLL = NULL;
        while(currLL->title != title){
          prevLL = currLL;
          currLL = currLL->next;
        }
        prevLL->next = currLL->next;
        delete currLL;
        del = true;

      }
    }
    else{
      //if LL is empty
      cout << "Movie: " << title << " not found, cannot delete." << endl;
    }
  }

  if(temp->head == NULL){
    //means LL is now empty have to delete TreeNode
    //cout<<"tree node's LL is empty..."<<endl;
    // if(temp->titleChar == root->titleChar){
    //   deleteNode(root,root->titleChar);
    // }
    root = deleteNode(root,temp->titleChar);

  //   TreeNode *curr = root;
  //   TreeNode *prev = NULL;
  //   bool left= false;
  //   while(curr->titleChar!=temp->titleChar){
  //     if(temp->titleChar < curr->titleChar){
  //       prev = curr;
  //       curr = curr->leftChild;
  //       left = true;
  //     }
  //     else{
  //       prev = curr;
  //       curr = curr->rightChild;
  //       left = false;
  //     }
  //   }
  //   // cout<< "Current's tree node: " <<curr->titleChar<<endl;
  //   // cout<< "Previous's tree node: " <<prev->titleChar<<endl;
  //   //case 1: curr has no children
  //   if((curr->leftChild == NULL)&& (curr->rightChild==NULL)){
  //     if(curr == root){
  //       root = NULL;
  //       return;
  //     }
  //
  //
  //     if(prev->leftChild == curr){
  //       prev->leftChild == NULL;
  //     }
  //     else{
  //       prev->rightChild == NULL;
  //     }
  //     delete curr;
  //     return;
  //   }
  //   //case 2: pres has 1 child
  //   if(curr->rightChild == NULL){
  //     //pres has left child
  //     if(curr == root){//edge case
  //       root = root->leftChild;
  //       return;
  //     }
  //
  //     if(prev->leftChild == curr){
  //       prev->leftChild == curr->leftChild;
  //     }
  //     else{
  //       prev->rightChild == curr->leftChild;
  //     }
  //     delete curr;
  //     return;
  //   }
  //   if(curr->leftChild == NULL){
  //     //pres has right child
  //     if(curr == root){//edge case
  //       root = root->rightChild;
  //       return;
  //     }
  //
  //     if(prev->leftChild == curr){
  //       prev->leftChild == curr->rightChild;
  //     }
  //     else{
  //       prev->rightChild == curr->rightChild;
  //     }
  //     delete curr;
  //     return;
  //   }
  //   //case 3
  //   if(curr->rightChild->leftChild == NULL){
  //     curr->titleChar = curr->rightChild->titleChar;
  //     curr->head = curr->rightChild->head;
  //     curr->rightChild = curr->rightChild->rightChild;
  //
  //     return;
  //   }
  //   TreeNode * succ = curr->rightChild;
  //   TreeNode * succParent = curr;
  //   //find successors node
  //   while(succ->leftChild !=NULL){
  //     succParent = succ;
  //     succ = succ->leftChild;
  //   }
  //   //time to delete current
  //   curr->titleChar = succ->titleChar;
  //   curr->head = succ->head;
  //   succParent->leftChild = succ->rightChild;
  //   delete curr;
  //
  //
  //   //
  //   // delete curr->rightChild;
  //   // delete curr->leftChild;
  //   // delete curr;
  //
  }



}
//g++ MovieTree.cpp MovieTreeDriver.cpp -o BTSLL
//BTSLL
