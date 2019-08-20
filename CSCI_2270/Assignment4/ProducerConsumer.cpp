#include "ProducerConsumer.hpp"
using namespace std;
#include <iostream>
ProducerConsumer::ProducerConsumer(){
  queueFront = -1;
  queueEnd = -1;
}

bool ProducerConsumer::isEmpty(){
  if((queueFront == -1) && (queueEnd == -1)){
    return true;
  }
  return false;
}
bool ProducerConsumer::isFull(){
  if(queueSize() == SIZE){
    return true;
  }
  return false;
}

void ProducerConsumer::enqueue(std::string item){
  if(isFull()){
    cout<<"Queue full, cannot add new item" <<endl;
  }
  else{
    if(queueFront ==-1){
      queueFront=0;
      queueEnd=0;
      queue[queueEnd] = item;
    }
    else{
      if(queueEnd == SIZE-1){
        queue[0]=item;
        queueEnd = 0;
      }
      else{
        queueEnd = queueEnd +1;
        queue[queueEnd] = item;
      }
    }


  }
}
void ProducerConsumer::dequeue(){
  if(isEmpty()){
    cout<< "Queue empty, cannot dequeue an item" <<endl;
  }
  else{
    if(queueFront == queueEnd){
      queueFront = -1;
      queueEnd = -1;
    }
    else{
      if(queueFront == SIZE -1){
        queueFront =0;
      }
      else{
        queueFront ++;
      }
    }
    // queue[queueFront]= "";
    // queueFront++;
    // if(queueFront == -1){
    //   queueEnd = -1;
    // }
  }
}
int ProducerConsumer::queueSize(){
  if(isEmpty()){
    return 0;
  }
  if(queueFront <= queueEnd){
    return (queueEnd - queueFront +1);
  }
  return SIZE -(queueFront - queueEnd)+1;
}
string ProducerConsumer::peek(){
  if(isEmpty()){
    cout<<"Queue empty, cannot peek" <<endl;
    return "";
  }
  else{
    return queue[queueFront];
  }
}
