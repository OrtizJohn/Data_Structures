/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  //check functions
  // RPNCalculator r1;
  // r1.isEmpty();//works
  // r1.push(1);
  // // cout<<r1.peek()->number<<endl;
  // r1.push(2);
  // // cout<<r1.peek()->number<<endl;
  // r1.push(3);
  // // cout<<r1.peek()->number<<endl;
  // r1.push(4);
  // // cout<<r1.peek()->number<<endl;
  // r1.pop();
  // // cout<<r1.peek()->number<<endl;
  // r1.compute("+");
  // cout<<r1.peek()->number<<endl;
  /////////////////////////////////////////////////////////////////////



  // TODO - Declare a stack to hold the operands
  RPNCalculator r1;
  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;
  bool go = true;
  while(go)
  {
    string ch;
    //getline(cin,ch);
    cout << "#> ";
    getline(cin,ch);
    if(isNumber(ch)){
      r1.push(stof(ch));
    }
    else if(("+" == ch) || ("*" == ch)){
      r1.compute(ch);
    }
    if(ch == "="){
      go = false;
    }
    /* TODO
       1. Read input (operators and operands) until you encounter a "="
       2. Use the isNumber function to check if the input is an operand
       3. push all operands to the stack
       4. If input is not an operand, call the compute function to evaluate
          the partial expression
    */

  }
  if(r1.isEmpty()){
    cout << "No operands: Nothing to evaluate" <<endl;
    return 0;
  }

  float temp = r1.peek()->number;
  r1.pop();
  if(r1.isEmpty()){
    cout<<temp<<endl;
  }
  else{
    cout<<"Invalid expression"<<endl;
    return 0;
  }


  /* TODO - If the stack is empty then print "No operands: Nothing to evaluate" */

  /* TODO - Validate the expression
      1. If valid then print the result
      2. Else, print "Invalid expression"*/

  return 0;
}
