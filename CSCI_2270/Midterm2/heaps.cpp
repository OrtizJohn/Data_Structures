#include "heaps.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


Heap::Heap(int heapSize)
{
  currentSize = 0;
  this->heapSize = heapSize;
  heap = new float[heapSize];
}

Heap::~Heap(){

}

void Heap::printHeap()
{
  int iter = 0;
  while(iter < currentSize)
  {
    cout<<heap[iter]<<" ";
    iter = iter + 1;
  }
  cout<<endl;
}

void Heap::addToHeap(float value){
  if(currentSize == heapSize)
  {
    cout<<"Maximum heap size reached. Cannot insert anymore"<<endl;
    return;
  }

  currentSize = currentSize + 1;
  int index = currentSize - 1;
  heap[index] = value;
  repairUpward(currentSize-1);



}

float Heap::removeFromHeap(){
  if(isEmpty()){
    //cout << "Heap empty, cannot delete" << endl;
    return 0;
  }

  heap[0]=heap[currentSize-1];
  currentSize--;
  repairDownward(0);
  return heap[0];
}


/////////////////////////////////helpers for indexes
int Heap::parent(int index)
{
  return (index-1)/2;
}

/*
Returns the left child of a node.
*/
int Heap::leftChild(int index)
{
  return ((2*index) + 1);
}

/*
Returns the right child of a node.
*/
int Heap::rightChild(int index)
{
  return ((2*index) + 2);
}
//swaps
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

bool Heap::isEmpty(){
  if(currentSize == 0){
    return true;
  }
  return false;
}
bool Heap::isFull(){
  if(currentSize == heapSize){
    return true;
  }
  else{
    return false;
  }
}
////////////////////////////////////////////this is designed for a min heap flip signs for max
void Heap::repairUpward(int nodeIndex){
  if(heap[parent(nodeIndex)] > heap[nodeIndex]){
    swap(heap[nodeIndex], heap[parent(nodeIndex)]);
    repairUpward(parent(nodeIndex));
  }

  else{
    if(nodeIndex != parent(nodeIndex)){
      return;
    }
  }

}

void Heap::repairDownward(int nodeIndex){
  int l = leftChild(nodeIndex);
  int r = rightChild(nodeIndex);
  int smallest = nodeIndex;
  //
  // cout<< "current node size: " << priorityQueue[smallest].groupSize<<endl;
  // cout<< "left child size: " << priorityQueue[l].groupSize << endl;
  // cout<< "right child size: " << priorityQueue[r].groupSize <<endl;
  if(l< currentSize){
    if(heap[smallest]> heap[l]){
      smallest = l;
    }


  }
  if(r < currentSize){
    if(heap[smallest]> heap[r]){
      smallest = r;
    }

  }

  if(smallest== nodeIndex){
    return;
  }
  else{
    swap(heap[smallest],heap[nodeIndex]);
    repairDownward(smallest);
  }
}

float Heap::peekValue(){
  if(isEmpty()){
    //cout << "Heap empty, nothing to peek" << endl;

  }
  return heap[0];
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//only change I made was to have the size to go with the array
float* heapSort(float arr[],int size){ //going to return a pointer to an array of floats
  Heap h1(size);//creates heap
  for(int i=0; i<size;i++){//adds each float from array to heap
    if(arr[i]!= 0){//make sure no empty values
      h1.addToHeap(arr[i]);//adds to heap
    }

  }
  //h1.printHeap();
  float *temp = new float[size];//creates another array of floats
  int count = 0;//keeps track of the indexes
  while(!h1.isEmpty()){//runs till the heap will be empty
    temp[count] = h1.peekValue();//adds what was in the heap to array
    h1.removeFromHeap();//removes that value from heap
    count ++;//increments count
  }
  //
  // for(int i=0; i<size;i++){
  //   temp[i] = h1.peekValue();
  //   h1.removeFromHeap();
  // }
  return temp;//returns the pointer to the array
}

int main(){
  cout << "Test case 1: "<< endl;
  float arr[9]={9.1,13,10,14,15.1,12.2,11.5,8.6};
  int size = 9;

  cout<< "Array unsorted: " <<endl;
  cout << "[ ";
  for(int i=0;i<size;i++){
    if(arr[i]!=0){
      cout<< arr[i];
      cout<<" ";
    }


  }
  cout<< "]" <<endl;





  float *temp = heapSort(arr,size);


  cout<< "Array sorted: " <<endl;
  cout << "[ ";
  for(int i=0;i<size;i++){
    if(temp[i]!= 0){
      cout<< temp[i];
      if(i!=size-1){
        cout<< " ";
      }
    }

  }
  cout<< "]" <<endl;

  cout << "Test case 2: "<< endl;
  float arr2[]={5.1};
  int size2 = 1;

  cout<< "Array unsorted: " <<endl;
  cout << "[ ";
  for(int i=0;i<size2;i++){
    if(arr2[i]!=0){
      cout<< arr2[i];
      cout<<" ";
    }


  }
  cout<< "]" <<endl;





  float *temp2 = heapSort(arr2,size2);


  cout<< "Array sorted: " <<endl;
  cout << "[ ";
  for(int i=0;i<size2;i++){
    if(temp2[i]!= 0){
      cout<< temp2[i];
      if(i!=size2-1){
        cout<< " ";
      }
    }

  }
  cout<< "]" <<endl;

}
