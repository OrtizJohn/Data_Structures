#include "PriorityQueue.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
using namespace std;





void printMenu(){
  cout << "============Main Menu============" << endl;
  cout << "1. Get group information from file" << endl;
  cout << "2. Add a group to Priority Queue" << endl;
  cout << "3. Show next group in the queue" << endl;
  cout << "4. Serve Next group" << endl;
  cout << "5. Serve Entire Queue" << endl;
  cout << "6. Quit" << endl;

}


int main(int argc,char* argv[]){
  PriorityQueue p1(stoi(argv[1]));





  bool go = true;

  while(go){
    printMenu();
    string ans="";
    getline(cin,ans);



    if(stoi(ans)==1){
      string filename;
      cout << "Enter filename:" << endl;
      getline(cin,filename);

      ifstream inFile(filename);
      if(inFile.fail()){
        std::cout<< "Failed to open the file." <<std::endl;

      }
      else{
        string line ="";
        int check = 0;
        while(getline(inFile,line)){
          stringstream  linestream(line);
          string word;
          string GName;
          string Gsize1;
          string CookTime1;

          while(linestream >> GName>>Gsize1>>CookTime1){
            // cout<<GName<<endl;
            // cout<<Gsize1<<endl;
            // cout<<CookTime1<<endl;
            if(!p1.isFull()){
              p1.enqueue(GName,stoi(Gsize1),stoi(CookTime1));

            }
            else if(check!=1){
              cout << "Heap full, cannot enqueue" << endl;
              check++;
            }

          }
        }


        //   if(p1.isFull()){
        //     cout << "Heap full, cannot enqueue" << endl;
        //     break;
        //   }
        //   else{
        //     //p1.enqueue(GName,stoi(Gsize1),stoi(CookTime1));
        //   }



        }
      }





		else if(stoi(ans) == 2){
      string GName,Gsize1,CookTime1;
      cout << "Enter Group Name:" << endl;
      getline(cin,GName);
      cout << "Enter Group Size:" << endl;
      getline(cin,Gsize1);
      cout << "Enter Estimated Cooking Time:" << endl;
      getline(cin,CookTime1);
      p1.enqueue(GName,stoi(Gsize1),stoi(CookTime1));
		}
    else if(stoi(ans)==3){
      if(p1.isEmpty()){
        cout << "Heap empty, nothing to peek" << endl;

      }
      else{
        cout << "Group Name: " << p1.peek().groupName << endl;
        cout << "Group Size: " << p1.peek().groupSize << endl;
        cout << "Group Time: "<< p1.peek().cookingTime<< endl;
      }


    }
    else if(stoi(ans)==4){
      if(p1.isEmpty()){
        cout << "Heap empty, cannot dequeue" << endl;
      }
      else{
        int totalCookTime =0;
        totalCookTime += p1.peek().cookingTime;
        p1.dequeue();

        cout << "Group Name: " << p1.peek().groupName<< " - Total Cook Time for the Group: "<< totalCookTime << endl;
      }

    }
    else if(stoi(ans)==5){
      if(p1.isEmpty()){
        cout << "Heap empty, cannot dequeue" << endl;
      }
      else{
        int totalCookTime =0;
        while(!p1.isEmpty()){

          totalCookTime += p1.peek().cookingTime;


          cout << "Group Name: " << p1.peek().groupName<< " - Total Cook Time for the Group: "<< totalCookTime << endl;
          p1.dequeue();
        }

      }
    }
		else if(stoi(ans)==6){
      cout << "Goodbye!" << endl;
      go = false;
    }

  }







  // p1.enqueue("Bob",2,15);
  // p1.enqueue("John",4,25);
  // p1.enqueue("Mary",3,10);
  // p1.enqueue("Daphne",2,10);
  // //cout<<endl;
  //
  //
  // p1.dequeue();

}
