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
      stack<string> opStack;

      regex numP("\\d+");
      regex opP("[+-*/]");
      for (int i = 0; i < tokens.size(); i++){
        if (regex_match(tokens[i],numP)){
          numStack.push(stoi(tokens[i]));
        }
        else if (regex_match(tokens[i],opP)){
          //is a operator
          int num_1;
          int num_2;
          if (numStack.size() >= 2){
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

