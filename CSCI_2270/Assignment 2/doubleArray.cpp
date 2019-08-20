#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <sstream>
#include <iomanip>

using namespace std;
struct wordItem {
  string word;
  int count;
};

wordItem *resize(wordItem *arrayPtr, int &capacity)
{
	// TODO increase the capacity by two times

  cout<<"Resizing from "<<capacity<<" to "<<capacity*2<<endl;

	// TODO dynamically allocate an array of size newCapacity
	wordItem *newArray = new wordItem[capacity*2];

	// TODO copy all data from oldArray to newArray
	//cout<< "capacity: " <<*capacity <<endl;
	for(int i=0;i<capacity;i++){
		// cout << i << ": " << **arrayPtr+i<<endl;

		newArray[i].word= arrayPtr[i].word;
    newArray[i].count=arrayPtr[i].count;
	}

	// TODO free the memory associated with oldArray
	delete [] arrayPtr;//frees memory
	arrayPtr = newArray;
	capacity = capacity*2;
  return arrayPtr;


}

int main(){
  wordItem *uniqueWords;
  uniqueWords = new wordItem[100];
  int capacity =100;
  int uniqueWordCount=0;
  for(int i=0;i<1500;i++){
    wordItem w1;
    w1.word = "cool";
    w1.count =1;
    uniqueWords[uniqueWordCount] = w1;
    uniqueWordCount++;
    if(uniqueWordCount == capacity){
      uniqueWords = resize(uniqueWords, capacity);
    }
  }













}
