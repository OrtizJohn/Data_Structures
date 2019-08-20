#include <iostream>
#include<fstream>
#include <string>

struct User {
  std::string username;
  float gpa;
  int age;
};


void addUser(User users[], std::string _username, float _gpa, int _age, int
length){
  if(length<= 100){
    User u;
    u.username = _username;
    u.gpa= _gpa;
    u.age= _age;
    users[length] = u;
  }

}

void printList(const User users[], int length){
  for(int i=0;i<length;i++){

    std::cout << users[i].username << " [" << users[i].gpa << "] age: " <<users[i].age << std::endl;
  }


}


int main(int argc, char *argv[]){
  std::ifstream inFile(argv[1]);
  if(inFile.fail()){
    std::cout<< "Failed to open the file." <<std::endl;

  }
  else{


    User users[100];
    std::string line="";
    int numLines=0;
    while(getline(inFile,line)){
      if(line!=""){
        numLines++;
      }
    }
    //std::cout<< "numLines: " << numLines <<std::endl; //check number of lines in csv inFile
    std::string user1,gpa1,age1;
    float gpa2;
    int age2;
    int count = 0;
    inFile.clear();
    inFile.seekg(0, std::ios::beg);
    for(int i=0;i<numLines;i++){

      getline(inFile,user1,',');
      //std::cout<<user1<<std::endl;
      getline(inFile,gpa1,',');
      gpa2 = stof(gpa1);

      //std::cout<<gpa1<<std::endl;
      getline(inFile,age1,'\n');
      age2 = stoi(age1);
      //std::cout<<age1<<std::endl;
      addUser(users,user1,gpa2,age2,count);
      count ++;

    }
    inFile.close();
    printList(users,count);
    
    std::ofstream outFile(argv[2]);
    if(outFile.fail()){
      std::cout<< "Failed to open the file." <<std::endl;

    }
    else{
      std::string temp="";
      temp += argv[3];
      //std::cout<<temp<<std::endl; //check
      for(int i=0;i<count;i++){
        if(users[i].gpa >= stof(temp)){
          outFile<< users[i].username << "," << users[i].gpa << ","<< users[i].age <<std::endl;
        }
      }
    }
    outFile.close();

  }
}
