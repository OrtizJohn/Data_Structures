/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <string>
#include <iostream>
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
  bool userDone = 0;
  int input = 0;
  CountryNetwork c1;
  // c1.insertCountry(NULL, "USA");
  // c1.insertCountry(NULL, "Australia");
  // c1.insertCountry(NULL, "Mexico");
  // c1.deleteCountry("Mexico");
  //c1.loadDefaultSetup();
  //c1.printPath();
  //c1.reverseEntireNetwork();
  // c1.transmitMsg("United States", "I like pie");
  // c1.transmitMsg("United States", "I like dogs");
  //c1.deleteEntireNetwork();


  /////////////////////////////////////////
  while(userDone != 1){
    displayMenu();
    cin>> input;
    string name;
    string msg;
    string prevName;
    switch(input){
      case 1: c1.loadDefaultSetup();
              c1.printPath();
              break;
      case 2: c1.printPath();
              break;
      case 3:
              cin.ignore();
              cout << "Enter name of the country to receive the message:" <<endl;
              name="";
              getline(cin,name);
              cout<< "Enter the message to send:"<<endl;
              msg="";
              getline(cin,msg);
              cout<<endl<<endl;
              c1.transmitMsg(name,msg);
              break;
      case 4: cin.ignore();
              cout<< "Enter a new country name:" <<endl;
              name="";
              getline(cin,name);
              cout<< "Enter the previous country name (or First):" <<endl;
              getline(cin,prevName);
              while((c1.searchNetwork(prevName) == NULL) && (prevName != "First")){
                cout << "INVALID country...Please enter a VALID previous country name:" << endl;
                //cout<< "Enter the previous country name (or First):" <<endl;
                prevName = "";
                getline(cin,prevName);
              }
              cout<<endl;
              if(prevName == "First"){
                c1.insertCountry(NULL,name);
                c1.printPath();
              }
              else{
                c1.insertCountry(c1.searchNetwork(prevName),name);
                c1.printPath();
              }
              break;
      case 5: cin.ignore();
              cout << "Enter a country name:" <<endl;
              name="";
              getline(cin,name);
              c1.deleteCountry(name);
              c1.printPath();

              break;
      case 6: c1.reverseEntireNetwork();
              c1.printPath();
              break;
      case 7: c1.deleteEntireNetwork();
              break;
      case 8: cout << "Quitting... cleaning up path: " << endl;
              c1.printPath();
              c1.deleteEntireNetwork();
              if(c1.isEmpty()){
                cout << "Path cleaned" << endl;
              }
              else{
                cout << "Error: Path NOT cleaned" << endl;
              }
              cout << "Goodbye!" << endl;
              userDone =1;
              break;
      default: cout<< "Enter valid option..." <<endl;
    }

  }

}

/*
 * Purpose: displays a menu with options
 */
void displayMenu()
{
    cout << endl;
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Delete Country " << endl;
    cout << " 6. Reverse Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
