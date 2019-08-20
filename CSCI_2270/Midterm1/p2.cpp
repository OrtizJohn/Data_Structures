#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//used same base of the linked list from problem 1
struct Node{//creates struct that is nodes
  int key;
  Node* prev;
  Node* next;


  Node(){//basic constructor
    key= -1;
    next =0;
    prev= 0;
  }
  Node(int val){//if want to add nodes with values another constructor
    key = val;
    next = 0;
    prev = 0;

  }
};

class LinkedList{
private:

public:
  Node *head;
  Node *tail;

  LinkedList(){
    head =0;
    tail =0;
  }
  Node* search(int val) {
    Node* temp = head;
    while(temp!=0){
      if(temp->key == val){
        return temp;
      }
      temp = temp->next;
    }
    return 0;
    // for (Node* tmp = head; tmp!= 0; tmp=tmp->next) {
    //   if (tmp->key == val) return tmp;
    // }
    // return 0;
  }
  void insert(int value,Node *before){
    Node *nn = new Node(value);
    //if node before is empty meaning they want it inserted at the front of the LinkedList
    if(before==NULL){
      nn->next = head;
      if (head != NULL) head->prev = nn;
      head = nn;
      if (tail == NULL) {
        tail = nn;
      }
    }
    //if node after is NUll this means is will be inserted at the end of the LinkedList
    else if(before->next == NULL){
      nn->prev = before;
      tail->next = nn;
      tail  = nn;
    }
    else{
      //any case where wanted inserted in the middle
      Node* after = before->next;
      before->next = nn;
      nn->prev = before;
      after->prev = nn;
      nn->next = after;
    }

  }

};

void print(LinkedList l1) {//created out side class so can call in split
  //goes through list and prints
  for (Node* temp = l1.head; temp!= 0; temp=temp->next) {
    cout << temp->key << " ";
  }
  std::cout << std::endl;
}

void split(LinkedList l1){
  if(l1.head == NULL){//for edge case if linklist is empty
    cout<<"List is empty, can't split..." <<endl;
    return;
  }
  //goes through list to check if even and odd
  LinkedList Even;//creates even linked LinkedList
  LinkedList Odd;//creates odd linked LinkedList
  Node *lastEven = new Node();//node to track even nodes last inserted node
  lastEven=0;
  Node *lastOdd = new Node();//node to track odd nodes last inserted node
  lastOdd=0;
  for (Node* temp = l1.head; temp!= 0; temp=temp->next) {//runs through initial linked list
    if(temp->key%2 == 0){//checks if even
      //cout<<temp->key<<endl;//check to make sure they are even
      Even.insert(temp->key,lastEven);
      lastEven = Even.search(temp->key);
    }
    else{//for all other case cause it has to odd
      Odd.insert(temp->key,lastOdd);
      lastOdd = Odd.search(temp->key);
    }

  }



  cout<<"Even LinkedList:";
  print(Even);//prints even linked list
  cout<<endl;
  cout<<"Odd LinkedList:";
  print(Odd);//prints odd LinkedList


}
int main(){
  LinkedList l1;

  cout<< "Test case 1:" <<endl;//general case with negatives to  check if it accounts for that
  l1.insert(-9,0);
  l1.insert(-2,l1.search(-9));
  l1.insert(4,l1.search(-2));
  l1.insert(-4,l1.search(4));
  print(l1);
  split(l1);


  cout<<endl;

  LinkedList l2;
  cout<< "Test case 2:" <<endl;//general case with more to make sure that it can handle more nodes
  cout<< "Expected outcome: 68" <<endl;
  l2.insert(15,0);
  l2.insert(12,l2.search(15));
  l2.insert(19,l2.search(12));
  l2.insert(22,l2.search(19));
  l2.insert(12,l2.search(15));
  l2.insert(19,l2.search(12));
  l2.insert(22,l2.search(19));
  print(l2);
  split(l2);


  cout<<endl;


  LinkedList l3;
  cout << "Test case 3:" <<endl;//edge case
  cout<< "Expected outcome: List empty" <<endl;
  split(l3);

  return 0;
}
