#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int max_gap_finder(priority_queue<int, vector<int>, greater<int> >& q){
  int max_gap = 0;
  int first = q.top();
  q.pop();
  while (!q.empty()){
    if (abs(q.top()-first) > max_gap){
      max_gap = abs(q.top()-first);
      q.pop();
    }
  }
  return max_gap;
}

int main(){
  string s = "";
  priority_queue<int, vector<int>, greater<int> > input_queue;
  int input_num = 0;
  while (cin >> input_num){
    input_queue.push(input_num);
  }
  cout << max_gap_finder(input_queue) << endl;
  
  return 0;

}
