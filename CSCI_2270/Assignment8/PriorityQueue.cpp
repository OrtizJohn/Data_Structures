#include "PriorityQueue.hpp"
#include <iostream>
#include <string>
#include <fstream>


#include <iomanip>
using namespace std;


PriorityQueue::PriorityQueue(int queueSize){
  maxQueueSize = queueSize;
  currentQueueSize =0;
  priorityQueue = new GroupNode [queueSize];
  
}
PriorityQueue::~PriorityQueue(){
  //deallocate all memory
  for(int i=0;i< currentQueueSize;i++){
    priorityQueue[i].groupName = "";
    priorityQueue[i].groupSize = 0;
    priorityQueue[i].cookingTime = 0;
    currentQueueSize--;
  }
  delete []priorityQueue;
}

void PriorityQueue::enqueue(std::string _groupName, int _groupSize, int _cookingTime){
  GroupNode temp;
  temp.groupName = _groupName;
  temp.groupSize = _groupSize;
  temp.cookingTime = _cookingTime;
  if(currentQueueSize < maxQueueSize){
    priorityQueue[currentQueueSize] = temp;
    currentQueueSize++;
    repairUpward(currentQueueSize-1);
  }

  else{
    cout << "Heap full, cannot enqueue" << endl;
  }

}

int parent(int index)
{
  return (index-1)/2;
}

int leftChild(int index)
{
  return ((2*index) + 1);
}


int rightChild(int index)
{
  return ((2*index) + 2);
}

void swap(GroupNode *a, GroupNode *b)
{
  GroupNode temp = *a;
  //cout << "we swapping"<<endl;
  *a = *b;
  *b = temp;
}


void PriorityQueue::repairUpward(int nodeIndex){
  if(priorityQueue[parent(nodeIndex)].groupSize > priorityQueue[nodeIndex].groupSize){
    swap(&priorityQueue[nodeIndex], &priorityQueue[parent(nodeIndex)]);
    repairUpward(parent(nodeIndex));
  }
  else if(priorityQueue[parent(nodeIndex)].groupSize == priorityQueue[nodeIndex].groupSize){
    if(priorityQueue[parent(nodeIndex)].cookingTime > priorityQueue[nodeIndex].cookingTime){
      swap(&priorityQueue[nodeIndex], &priorityQueue[parent(nodeIndex)]);
      repairUpward(parent(nodeIndex));
    }
  }
  else{
    if(nodeIndex != parent(nodeIndex)){
      return;
    }

  }

}

void PriorityQueue::dequeue(){
  if(isEmpty()){
    cout << "Heap empty, cannot dequeue" << endl;
    return;
  }

  priorityQueue[0]=priorityQueue[currentQueueSize-1];
  currentQueueSize--;
  repairDownward(0);

}

bool PriorityQueue::isFull(){
  if(currentQueueSize == maxQueueSize){
    return true;
  }
  else{
    return false;
  }
}

bool PriorityQueue::isEmpty(){
  if(currentQueueSize == 0){
    return true;
  }
  return false;
}
void PriorityQueue::repairDownward(int nodeIndex){
  int l = leftChild(nodeIndex);
  int r = rightChild(nodeIndex);
  int smallest = nodeIndex;
  //
  // cout<< "current node size: " << priorityQueue[smallest].groupSize<<endl;
  // cout<< "left child size: " << priorityQueue[l].groupSize << endl;
  // cout<< "right child size: " << priorityQueue[r].groupSize <<endl;
  if(l< currentQueueSize){
    if(priorityQueue[smallest].groupSize > priorityQueue[l].groupSize){
      smallest = l;
    }
    else if(priorityQueue[smallest].groupSize == priorityQueue[l].groupSize){
      if(priorityQueue[smallest].cookingTime > priorityQueue[l].cookingTime){
        smallest = l;
      }
    }

  }
  if(r < currentQueueSize){
    if(priorityQueue[smallest].groupSize > priorityQueue[r].groupSize){
      smallest = r;
    }
    else if(priorityQueue[smallest].groupSize == priorityQueue[r].groupSize){
      if(priorityQueue[smallest].cookingTime > priorityQueue[r].cookingTime){
        smallest = r;
      }
    }
  }

  if(smallest== nodeIndex){
    return;
  }
  else{
    swap(&priorityQueue[smallest],&priorityQueue[nodeIndex]);
    repairDownward(smallest);
  }
}

GroupNode PriorityQueue::peek(){
  if(isEmpty()){
    cout << "Heap empty, nothing to peek" << endl;

  }
  return priorityQueue[0];
}
