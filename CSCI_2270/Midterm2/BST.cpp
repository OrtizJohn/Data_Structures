#include <iostream>
#include "BST.hpp"
#include <vector>
#define COUNT 10

BST::BST(){

}
BST::BST(int data){
  root = createNode(data);
  cout<< "New tree created with "<<data<<endl;
}


void BST::destroyNode(Node *currNode){
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = NULL;
     }
 }


BST::~BST(){
  destroyNode(root);
}



/////////////////////////////////add node
Node* BST::createNode(int data){
  Node* temp = new Node();
  temp->key =data;
  return temp;
}
Node* BST::addNodeHelper(Node* currNode, int data){
  if(currNode == NULL){
      return createNode(data);
  }
  else if(currNode->key < data){
      currNode->right = addNodeHelper(currNode->right,data);
  }
  else if(currNode->key > data){
      currNode->left = addNodeHelper(currNode->left,data);
  }
  return currNode;
}


void BST:: addNode(int data)
{
    root = addNodeHelper(root, data);
    cout<<data<<" has been added"<<endl;
}



/////////////////////////////////////////////////////////////////////////////////////////
Node* getMinValueNode(Node* currNode){

    if(currNode->left == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->left);
}


Node* BST::deleteNodeHelper(Node *currNode, int value){
  if(currNode == NULL)
  {
    return NULL;
  }
  else if(value < currNode->key)
  {
    currNode->left = deleteNodeHelper(currNode->left, value);
  }
  else if(value > currNode->key)
  {
    currNode->right = deleteNodeHelper(currNode->right, value);
  }
  // We found the node with the value
  else
  {
    //TODO Case : No child
    if(currNode->left == NULL && currNode->right == NULL)
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
    else if(currNode->left == NULL)
    {
      /*
      1.create a not temp
      2.make temp = current nodes
      3.shift current node to its right child
      4.delete temp
      */
      Node *temp = currNode;
      currNode = currNode->right;
      delete temp;

    }

    else if(currNode->right == NULL)
    {
      /*
      1.create a not temp
      2.make temp = current nodes
      3.shift current node to its left child
      4.delete temp
      */
      Node *temp = currNode;
      currNode = currNode->left;
      delete temp;

    }

    else
    {
      /*
      1.create a node main
      2.get the min value of the right subtree and store it in main
      3.replace the key of current node with the key of main
      4.call deleteNOde() as a recursive function into the right subtree of current node to delete the duplicate
      */
      Node *min = getMinValueNode(currNode->right);
      currNode->key = min->key;
      currNode->right = deleteNodeHelper(currNode->right, min->key);
      ///Replace with Minimum from right subtree

    }

  }
  return currNode;
}

void BST::deleteNode(int value){
  deleteNodeHelper(root, value);
}

///////////////////////////////////////////////////////////////////////search
Node* BST::searchKeyHelper(Node* currNode, int data){
    if(currNode == NULL)
        return NULL;

    if(currNode->key == data)
        return currNode;

    if(currNode->key > data)
        return searchKeyHelper(currNode->left, data);

    return searchKeyHelper (currNode->right, data);
}

// This function will return whether a key is in the tree
bool BST::searchKey(int key){
    Node* tree = searchKeyHelper(root, key);
    if(tree != NULL) {
        return true;
    }
    //cout<<"Key not present in the tree"<<endl;
    return false;
}
//////////////////////////////////////////////////////////////////////////// prints in 2d format
void BST::print2DUtilHelper(Node *currNode, int space)
{
    // Base case
    if (currNode == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}

void BST::print2DUtil( int space)
{
  print2DUtilHelper(root, space);
}
////////////////////////////////////////////////////////////////////////prints
void BST:: printTreeHelper(Node* currNode){
     if(currNode)
     {
        printTreeHelper( currNode->left);
        cout << " "<< currNode->key;
        printTreeHelper( currNode->right);
     }
 }

void BST:: printTree(){
     printTreeHelper(root);
     cout<<endl;
}



int BST::sumRange(int min, int max){
  int sum = 0;//creates integer variable
  for(int i= min;i<=max;i++){//runs through the range
    if(searchKey(i)){//checks if it is in the bst
      sum+= i;//adds to the sum
    }
  }
  cout<< "Sum of the range from " << min<< " to " <<max <<": " << sum<<endl;
}





int main(){
  cout<< "case1"<<endl;
  cout<<"Creating tree"<<endl;
  BST tree(10);


  tree.addNode(2); //left child to 5
  tree.addNode(1); //left child to 1
  tree.addNode(4); //right child to 2
  tree.addNode(7); //right child to 5
  tree.addNode(10); //right child of 7
  tree.addNode(8); // left child of 10
  tree.addNode(6); // left child of 7

  cout<<"----------------Intial tree is ---------------"<<endl<<endl;
  tree.printTree();
  tree.sumRange(1,4);
  // tree.print2DUtil(1);

  cout<<endl<<endl;
  cout<< "case2"<<endl;
  cout<<"Creating tree"<<endl;
  BST tree2(8);


  tree2.addNode(4);
  tree2.addNode(8);
  tree2.addNode(7);
  tree2.addNode(5);
  tree2.addNode(1);
  tree2.addNode(2);
  tree2.addNode(3);

  cout<<"----------------Intial tree is ---------------"<<endl;
  tree2.printTree();
  tree2.sumRange(7,8);
  // tree.print2DUtil(1);






  return 0;
}
