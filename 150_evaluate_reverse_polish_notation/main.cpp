//reverse polish notation evaluation
//use one stack for numbers, at each operator, get two numbers and compute the result, then push back to the number stack
//
//Time Complexity: O(n)
//Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <regex>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> numStack;
      string p = "+-*/";

      for (int i = 0; i < tokens.size(); i++){
          //is a operator
        int num_1;
        int num_2;
        if (p.find(tokens[i]) != string::npos  && numStack.size() >= 2){
          num_2 = numStack.top();
          numStack.pop();
          num_1 = numStack.top();
          numStack.pop();
        }
        if (tokens[i] == "+"){
          numStack.push(num_1+num_2); 
        }
        else if (tokens[i] == "-"){
          numStack.push(num_1-num_2);
        }
        else if (tokens[i] == "*"){
          numStack.push(num_1*num_2);
        }
        else if (tokens[i] == "/"){
          numStack.push(num_1/num_2);
        }
        else{
          //is a number
          numStack.push(stoi(tokens[i]));
        }

        //else error
      }
      
      while (!numStack.empty()){
        return numStack.top();
      }
      return -1;
    }
};

int main(){
  return 0;
}

