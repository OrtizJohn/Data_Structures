#include <iostream>
#include <array>
using namespace std;

bool isStopWord(string word, string ignoreWords[]){
  bool check = 0;
  for(int i=0;i<50;i++){
    if(word == ignoreWords[i]){

      check = 1;
    }


  }
  return check;
}
int main(){
  string words[20] = {
    "then","ab","back","aut","mox",
    "was","just","into","nec","dum",
    "cur","has","post","us","qui",
    "them","know","sic","dont","sive"
};

  cout << isStopWord("ab",words)<<endl;
}
