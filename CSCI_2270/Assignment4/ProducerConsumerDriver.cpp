/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
}

int main(int argc, char const *argv[])
{
	bool go = true;

	ProducerConsumer p1;
	while(go){
		string ans="";
		cout << "*----------------------------------------*" <<endl;
		menu();
		cout << "*----------------------------------------*" <<endl;
		getline(cin,ans);
		if(stoi(ans)==1){
			string numItems="";
			cout << "Enter the number of items to be produced:" << endl;
			getline(cin,numItems);
			for(int i=1;i<=stoi(numItems);i++){
				string item="";
				cout << "Item" << i << ":" << endl;
				getline(cin,item);
				p1.enqueue(item);
			}
		}
		else if(stoi(ans) == 2){
			bool check =false;
			string ans1 = "";
			cout << "Enter the number of items to be consumed:" << endl;
			getline(cin,ans1);

			if(stoi(ans1)>p1.queueSize()){
				check = true;
			}
			// int count =0;
			// while(count!=stoi(ans1)){
			// 	if(!p1.isEmpty()){
			// 		cout<< "Consumed: " <<p1.peek() << endl;
			// 		p1.dequeue();
			// 		count++;
			// 	}
			//
			// }
			for(int i=stoi(ans1);i>0;i--){
				// cout<< "i: " <<i <<endl;
				// cout<<"size: " << p1.queueSize() <<endl;
				if(!p1.isEmpty()){
					cout<< "Consumed: " <<p1.peek() << endl;
					p1.dequeue();
				}

			}
			if(check){
				cout<<"No more items to consume from queue"<<endl;
			}
		}
		else if(stoi(ans)==3){
			cout << "Number of items in the queue:" << p1.queueSize() <<endl;
			return 0;
		}
	}
}
