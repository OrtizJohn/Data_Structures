/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
  head = NULL;

}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
  if(head == NULL){
    return true;
  }
  return false;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
 void CountryNetwork::insertCountry(Country* previous, string countryName)
 {
   Country* newCountry = new Country;
   if(previous == NULL){
     newCountry->name  = countryName;
     newCountry->next = head;
     head = newCountry;
     cout << "adding: " << countryName << " (HEAD)" << endl;
   }
   else{
     newCountry->name = countryName;
     newCountry->next = previous->next;
     previous->next = newCountry;
     cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;

   }

 }
//done


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
 void CountryNetwork::deleteCountry(string countryName)
 {
   int count =1;
   int index= 0;
   Country* temp = head;
   while (temp != NULL){
       if(temp->name == countryName){
         index = count;
       }
       //cout <<count<< temp->name<<endl;
       temp = temp->next;
       count ++;
   }


   if (index == 0){
     cout<<"Country does not exist." <<endl;
   }
   else if(index ==1){
     Country* pres = head;
     Country* prev = pres;
     prev= pres->next;

     head = prev;
     delete pres;
     //cout << "hi" <<endl;
   }
   else{
     //cout<<index<<endl;
     Country* pres = head;
     Country* prev = NULL;
     for(int i=0;i<index-1;i++){
       prev = pres;
       pres = pres->next;
     }
     prev->next = pres->next;
     delete pres;
   }
 }
 //done


/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
  deleteEntireNetwork();
  Country* temp = head;
  head = temp;
  insertCountry(temp, "United States");
  insertCountry(searchNetwork("United States"),"Canada");
  insertCountry(searchNetwork("Canada"),"Brazil");
  insertCountry(searchNetwork("Brazil"),"India");
  insertCountry(searchNetwork("India"),"China");
  insertCountry(searchNetwork("China"),"Australia");

}
//done

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
  Country* temp = head;
  while (temp != NULL){
      if(temp->name == countryName){
        return temp;
      }
      //cout <<count<< temp->name<<endl;
      temp = temp->next;

  }
  return NULL;

}
//done

/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
 void CountryNetwork::deleteEntireNetwork()
 {
   Country* pres = head;

   if(pres == NULL){
     return;
   }
   while (pres != NULL){
       Country* prev = pres;
       cout << "deleting: " << prev->name << endl;
       delete prev;
       pres = pres->next;
   }
   cout << "Deleted network" << endl;
   head = NULL;
 }
//done

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
 void CountryNetwork::transmitMsg(string receiver, string message)
 {
   Country* temp = head;
   if(temp == NULL){
     cout << "Empty list" <<endl;
     return;
   }
   while (temp->name != receiver){
     temp->message = message;
     temp->numberMessages ++;
     cout << temp->name << " [# messages received: " << temp->numberMessages << "] received: " << temp->message << endl;
     temp = temp->next;
   }
   temp->message = message;
   temp->numberMessages ++;
   cout << temp->name << " [# messages received: " << temp->numberMessages << "] received: " << temp->message << endl;


 }



/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
  Country* temp = head;
  //cout << "== CURRENT PATH ==" <<endl;
  if(temp == NULL){
    cout << "== CURRENT PATH ==" <<endl;
    cout << "nothing in path"<<endl;
    cout << "===" << endl;
    return;
  }
  cout << "== CURRENT PATH ==" <<endl;
  while (temp!=NULL){
    cout << temp->name<< " -> ";
    temp = temp->next;
  }
  cout << "NULL" <<endl;
  cout << "===" << endl;

}


/*
 * Purpose: reverse the entire network t
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork()
{
  Country* pres = head;
  Country* prev = NULL;
  Country* next = NULL;
  while(pres != NULL){
    next = pres->next;
    pres->next = prev;
    prev = pres;
    pres =next;
  }
  head = prev;
}
node* reverse(node *head){
  node* pres = head;
  node* prev = NULL;
  node* next = NULL;
  while(pres != NULL){
    next = pres->next;
    pres->next = prev;
    prev = pres;
    pres =next;
  }
  head = prev;
  return head;
}
//done
