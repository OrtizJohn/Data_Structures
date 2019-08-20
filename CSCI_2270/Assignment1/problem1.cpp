#include <iostream>
#include <string>
#include <fstream>

int insertIntoSortedArray( int myArray[], int numEntries, int newValue){

  if(numEntries >=100){
    return 100;
  }
  myArray[numEntries] = newValue;
  numEntries++;

  for(int i=0;i<numEntries;i++){
    for(int j=i+1;j<numEntries;j++){
      if(myArray[i] >myArray[j]){
        int *p1 = &myArray[i];
        int *p2 = &myArray[j];
        int temp = *p1;
        *p1 = *p2;
        *p2= temp;
      }
    }
  }


  return numEntries;
}


int main(int argc, char *argv[]){
  //cout<< argv[1]<< endl; //note gets the name of the file
  std::ifstream inFile(argv[1]);
  if(inFile.fail()){
    std::cout<< "Failed to open the file." <<std::endl;

  }
  else{
    //std::cout<< "Works!!!" << std::endl; // check if if statement is working
    int numCounts =0;
    int nums[100];
    std::string line="";
    while(getline(inFile,line)){
      if(line!= ""){
          // std::cout<< line <<std::endl;
          // numCounts++;
          numCounts = insertIntoSortedArray(nums,numCounts,stoi(line));
          for(int i=0;i<numCounts;i++){
            std::cout<< nums[i];
            if(i!=numCounts-1){
              std::cout<< ",";
            }
          }
          std::cout<<std::endl;

      }


    }
    // std::cout<< "count: " << numCounts <<std::endl;
    //check if function works
    // int test[5] = {5,6,6,7};
    // insertIntoSortedArray(test, 4,6);
    // for(int i=0;i<5;i++){
    //   std::cout<<test[i] << " , ";
    // }
    // std::cout<< std::endl;
    //////////////////////////////////////


  }
}
