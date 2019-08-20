#include "HashTable.hpp"
#include <iostream>
#include <string>
#include <fstream>


#include <iomanip>
using namespace std;

HashTable::HashTable(int hashTableSize){
  hashTable = new wordItem* [hashTableSize];
  this->hashTableSize =hashTableSize;
  numItems = 0;
  numCollisions = 0;
  for (int i = 0; i < hashTableSize; i++) hashTable[i] = 0;
}
HashTable::~HashTable(){


  for(int i = 0; i<hashTableSize;i++){
    wordItem* curr = hashTable[i];
    while(curr != 0){
      wordItem* prev = curr;
      curr = curr->next;
      delete prev;
    }
    hashTable[i] = 0;

  }
  delete hashTable;
}

unsigned int HashTable::getHash(std::string word){
  unsigned int hashValue = 5381;
  int length = word.length();
  for (int i=0;i<length;i++)
  {
  hashValue=((hashValue<<5)+hashValue) + word[i];
  }
  hashValue %= hashTableSize;
  return hashValue;
}




void HashTable::addWord(std::string word)
{

        // create a new node with the key and insert it in this slot's list
        //calculate the index for keys..create a new node, nw with key and nullptr
        //check if table [index] is null
        //if yes, then assign nw to table[index]
        //if no, then assign table index to nw->next and assign nw to table[index]
        //return true
        wordItem* nw = new wordItem;
        int index = getHash(word);
        nw->word = word;
        nw->next = NULL;
        nw->count = 1;

        if(hashTable[index] == NULL){
          hashTable[index]= nw;
        }
        else{
          nw->next =  hashTable[index];
          hashTable[index] = nw;
          numCollisions++;
        }
        numItems++;
}
//done
bool HashTable::isInTable(std::string word){
  if(searchTable(word)!= NULL){
    return true;
  }
  else{
    return false;
  }
}

void HashTable::incrementCount(std::string word){
  if(searchTable(word)== NULL){
    return;
  }
  else{
    wordItem* temp = searchTable(word);
    temp->count = temp->count + 1;
  }
}

int HashTable::getNumCollisions(){
  return numCollisions;
}

int HashTable::getNumItems(){
  return numItems;
}


int HashTable::getTotalNumWords(){
  int count = 0;
  for(int i = 0; i<hashTableSize;i++){
    wordItem* temp = hashTable[i];
    while(temp != NULL){
      count += temp->count;
      temp = temp->next;
    }
  }
  return count;
}
//done



wordItem* HashTable::searchTable(std::string word){
  int index = getHash(word);
  wordItem * tmp = hashTable[index];
  while (tmp != NULL){
    if (tmp->word == word){
      return tmp;
    }
    tmp=tmp->next;
  }
  return 0;
}


void HashTable::printTopN(int n){
  wordItem** order = new wordItem*[numItems];
  int count = 0;
  for(int i=0;i<hashTableSize;i++){
    wordItem* temp = hashTable[i];
    while(temp!=0){
      order[count]= temp;
      count++;
      temp=temp->next;
    }
  }
  //cout<< "items in temp array: " <<count<<endl;
  //
  for(int i=0;i<count;i++){
		for(int j=i+1;j<count;j++){
			if(order[i]->count<order[j]->count){

				wordItem* temp  =order[i];
				order[i]=order[j];
				order[j]=temp;
			}
		}
	}
  // for(int i=0;i<10;i++){
  //   cout<< order[i]->word <<"- count: " << order[i]->count<<endl;
  // }

  for(int i=0;i<n;i++){

    float w = (float)order[i]->count/getTotalNumWords();
    cout <<fixed<< setprecision(4)<< w << " - " << order[i]->word << endl;
  }

  
}
