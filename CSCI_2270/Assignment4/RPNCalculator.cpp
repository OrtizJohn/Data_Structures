#include "RPNCalculator.hpp"
#include <iostream>

using namespace std;

RPNCalculator::RPNCalculator(){
  stackHead = NULL;
}
//done
RPNCalculator::~RPNCalculator(){
  Operand *temp = stackHead;
  while(temp!= NULL){
    pop();
    temp= temp->next;
  }
  stackHead = NULL;
}
//done
bool RPNCalculator::isEmpty(){
  // Operand *temp = stackHead;
  // while(temp!= NULL){
  //   cout<<temp->number << " , ";
  //   temp= temp->next;
  // }
  // cout<<endl;
  if(stackHead == NULL){
    return true;
  }
  else{
    return false;
  }
}
//done
void RPNCalculator::push(float number){
  Operand *nn = new Operand;
  nn->number = number;
  nn->next = stackHead;
  stackHead = nn;

}
void RPNCalculator::pop(){

  if(isEmpty()){
    cout<<"Stack empty, cannot pop an item."<<endl;
    return;
  }else{
    // Operand *temp = stackHead;
    // cout<<"Before popped: " <<endl;
    // while(temp!= NULL){
    //   cout<<temp->number << " , ";
    //   temp= temp->next;
    // }
    Operand *pres = stackHead;
    //cout << pres->number <<endl;
    Operand *prev = NULL;
    prev = pres;
    pres = pres->next;
    stackHead = pres;
    delete prev;
    // Operand *temp1 = stackHead;
    // cout << "After popped: " << endl;
    // while(temp1!= NULL){
    //   cout<<temp1->number << " , ";
    //   temp1= temp1->next;
    // }
  }

}

Operand* RPNCalculator::peek(){
  if(isEmpty()){
    cout<<  "Stack empty, cannot peek." <<endl;
    return NULL;
  }
  else{
    return stackHead;
  }
}

bool  RPNCalculator::compute(string symbol){
  float a,b,ans;
  if((symbol != "+") && (symbol != "*")){
    cout << "err: invalid operation"<<endl;
    return false;
  }
  if(isEmpty()){
     cout << "err: not enough operands" <<endl;
     return false;
  }
  else{

    a = stackHead->number;
    //cout << "a: " << a <<endl;
    pop();
    if(isEmpty()){
      cout << "err: not enough operands" <<endl;
      push(a);
      return false;
    }
    else{
      b = stackHead->number;
      //cout << "b: " << b <<endl;
      pop();

      if(symbol == "+"){
        ans = a + b;
        push(ans);
        return true;
      }
      else if (symbol == "*"){
        ans = a * b;
        push(ans);
        return true;
      }
    }


  }
}
