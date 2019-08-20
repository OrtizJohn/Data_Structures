#include "HashTable.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
using namespace std;




void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable){
    ifstream inFile(ignoreWordFileName);
    if(inFile.fail()){
      std::cout << "Failed to open " << ignoreWordFileName << std::endl;
    }
    else{
      int count =0;
      string line;
      while(getline(inFile,line)){
        stopWordsTable.addWord(line);
        count++;
        //cout << line<< endl;//check to see if get line working
        line= "";

      }
    }
}
//works with autograder

bool isStopWord(string word, HashTable &ignoreWords){

  return ignoreWords.isInTable(word);

}

int main(int argc,char* argv[]){
  if(argc != 5  )
	{
    cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" <<endl;
  }
  else{

  HashTable stopWordsTable(50);


  getStopWords(argv[3],stopWordsTable);
  //cout<<stopWordsTable.isInTable("bob")<<endl;

  //creating unique words hashtable

  HashTable uniqueWords(stoi(argv[4]));
// //     wordItem *uniqueWords;
// //   	uniqueWords = new wordItem[100];
// //     int capacity =100;
// //     //cout << sizeof(uniqueWords)<<endl;
    ifstream inFile(argv[2]);
    if(inFile.fail()){
      cout<< "Rip, sorry file sucks" <<endl;
    }
    else{
      string line="";




      while(getline(inFile,line)){
        stringstream  linestream(line);
        string word;
        while(linestream >> word){
          if(word!=""){

            if(!isStopWord(word,stopWordsTable)){
              //cout<< line<<endl;
              if(uniqueWords.isInTable(word)){
                uniqueWords.incrementCount(word);
              }
              else{
                uniqueWords.addWord(word);

              }
            }
          }
        }


      }
      uniqueWords.printTopN(stoi(argv[1]));
      cout << "#"<<endl;
      cout << "Number of collisions: " << uniqueWords.getNumCollisions() <<endl;
      cout << "#"<<endl;
      cout<< "Unique non-stop words: " << uniqueWords.getNumItems() <<endl;
      cout<< "#" <<endl;
      cout<< "Total non-stop words: " << uniqueWords.getTotalNumWords()<<endl;



    }
  }


}
