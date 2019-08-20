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
/////////////////////////////////////////////
//length = length*2;
// wordItem *arrTemp;
// arrTemp = new wordItem[length];
// delete ptr;
// ptr = arrTemp;
// delete arrTemp;
// arrTemp = NULL;
// Edit: I fixed it in moodle my removing the deletes
////////////////////////////////////////////////////////////
wordItem *resize(wordItem *arrayPtr, int &capacity)
{
	// TODO increase the capacity by two times

  //cout<<"Resizing from "<<capacity<<" to "<<capacity*2<<endl;

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
  capacity = capacity*2;
  delete [] arrayPtr;//frees memory
	arrayPtr = newArray;

  return arrayPtr;


}



void getStopWords(const char *ignoreWordFileName, string
ignoreWords[]){
    ifstream inFile(ignoreWordFileName);
    if(inFile.fail()){
      std::cout << "Failed to open " << ignoreWordFileName << std::endl;
    }
    else{
      int count =0;
      string line;
      while(getline(inFile,line)){
        ignoreWords[count] = line;
        count++;
        //cout << line<< endl;//check to see if get line working
        line= "";

      }
    }
}
bool isStopWord(string word, string ignoreWords[]){
  bool check = 0;
  for(int i=0;i<50;i++){
    if(word == ignoreWords[i]){

      check = 1;
    }


  }
  return check;
}
int getTotalNumberNonStopWords(wordItem uniqueWords[], int
length){
  int total=0;
  for(int i=0;i<length;i++){
    total += uniqueWords[i].count;
  }
  return total;
}

void arraySort(wordItem uniqueWords[], int length){
  for(int i=0;i<length;i++){
		for(int j=i+1;j<length;j++){
			if(uniqueWords[i].count<uniqueWords[j].count){
        wordItem temp;
				temp  =uniqueWords[i];
				uniqueWords[i]=uniqueWords[j];
				uniqueWords[j]=temp;
			}
		}
	}

}
void printTopN(wordItem uniqueWords[], int topN, int totalNumWords){
  for(int i=0;i<topN;i++){
    float prob = ((float)uniqueWords[i].count)/totalNumWords;
    cout <<fixed<< setprecision(4)<< prob << " - " << uniqueWords[i].word << endl;
  }
}



int main(int argc,const char* argv[]){
  if(argc != 4  )
	{
    cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" <<endl;
  }
  else{
    //std::cout<< "hi" <<std::endl;//check to see if correct amount of arguments is implemented with if statement
//call getStopWords function
  string *ignoreWords;
  ignoreWords = new string[50];

  getStopWords(argv[3],ignoreWords);
  /////////////////////////////////////
  //check if array stored
  // for(int i=0;i<50;i++){
  //   cout<<ignoreWords[i]<<endl;
  // }
  ////////////////////////////////////

//creating array of wordItems
    wordItem *uniqueWords;
  	uniqueWords = new wordItem[100];
    int capacity =100;
    //cout << sizeof(uniqueWords)<<endl;
    ifstream inFile(argv[2]);
    if(inFile.fail()){
      cout<< "Rip, sorry file sucks" <<endl;
    }
    else{
      string line="";

      int uniqueWordCount = 0;
      int resizeCount = 0;
      while(getline(inFile,line,' ')){
        if(line!=""){

          if(!isStopWord(line,ignoreWords)){
            //cout<< line<<endl;

            ///////////////////////////////////////////////////
            //check to see if word already in uniqueWords
            bool newWord = 0;
            for(int i=0;i<uniqueWordCount;i++){
              if(uniqueWords[i].word == line){
                newWord = 1;
                //uniqueWordCount++;
              }
            }

            if(uniqueWordCount==capacity){
              //cout << "Hit word array" <<endl;
              // for(int i=0;i<uniqueWordCount;i++){
              //   cout<< uniqueWords[i].word <<endl;
              // }
              uniqueWords = resize(uniqueWords,capacity);
              resizeCount ++;

            }


            if(newWord == 0){
                //cout<< "New word" <<endl;
                wordItem w1;
                w1.word = line;
                w1.count =1;
                uniqueWords[uniqueWordCount] = w1;
                uniqueWordCount++;

            }
            if(newWord == 1){
              //cout << "not new word" <<endl;
              for(int i=0;i<uniqueWordCount;i++){
                if(uniqueWords[i].word == line){
                  uniqueWords[i].count+=1;
                }
              }


            }

          }



        }
      }
      cout << "Array doubled: " << resizeCount <<endl;
      cout << "#"<<endl;
      cout<< "Unique non-common words: " << uniqueWordCount <<endl;
      cout<< "#" <<endl;
      cout<< "Total non-common words: " << getTotalNumberNonStopWords(uniqueWords,uniqueWordCount)<<endl;
      cout<< "#" <<endl;
      cout<< "Probabilities of top " << argv[1] << " most frequent words" <<endl;
      cout<< "---------------------------------------" <<endl;
      arraySort(uniqueWords,uniqueWordCount);
      printTopN(uniqueWords,stoi(argv[1]),getTotalNumberNonStopWords(uniqueWords,uniqueWordCount));
      // for(int i=0;i<uniqueWordCount;i++){
      //   cout << uniqueWords[i].count <<endl;
      // }
      ///cout<<numLines<<endl;


    }









  }
}
