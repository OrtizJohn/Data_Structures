#include <iostream>

using namespace std;


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
  void print() {
    //goes through list and prints
    for (Node* temp = head; temp!= 0; temp=temp->next) {
      cout << temp->key << " ";
    }
    std::cout << std::endl;
  }

  int sumEvens(){
    int sum =0;//creates sum variable to track sum
    Node *temp = head;//for going through linked list
    while(temp!=NULL){//goes through full list
      if((temp->key %2)== 0){//checks if even
        //cout<< temp->key<<endl; //checks to make sure running correctly
        sum = sum + temp->key;//adds to sum total
      }
      temp = temp->next;
    }
    return sum;//return the sum of the evens

  }
};

int main(){
  LinkedList l1;
  cout<< "Test case 1:" <<endl;//general case with negatives
  cout<< "Expected outcome: -2" <<endl;
  l1.insert(-9,0);
  l1.insert(-2,l1.search(-9));
  l1.insert(4,l1.search(-2));
  l1.insert(-4,l1.search(4));
  l1.print();
  cout<< "Even Sum: " << l1.sumEvens() << endl;

  cout<<endl;

  LinkedList l2;
  cout<< "Test case 2:" <<endl;//more numbers to test if it can handle it
  cout<< "Expected outcome: 68" <<endl;
  l2.insert(15,0);
  l2.insert(12,l2.search(15));
  l2.insert(19,l2.search(12));
  l2.insert(22,l2.search(19));
  l2.insert(12,l2.search(15));
  l2.insert(19,l2.search(12));
  l2.insert(22,l2.search(19));
  l2.print();
  cout<< "Even Sum: " << l2.sumEvens() << endl;


  cout<<endl;


  LinkedList l3;
  cout << "Test case 3:" <<endl;//edge case
  cout<< "Expected outcome: 0" <<endl;
  cout<< "Even Sum: " << l3.sumEvens() << endl;





}
