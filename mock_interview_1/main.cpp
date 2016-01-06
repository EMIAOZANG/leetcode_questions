#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool Sherlock(vector<int>& array){
  if (array.size() < 1){
    return false; //empty input
  }

  vector<int> leftSumArray;
  int sum = 0;
  leftSumArray.push_back(0);
  for (int i = 0; i < array.size(); i++){
    sum += array[i];
    leftSumArray.push_back(sum);
  }
  leftSumArray.push_back(0);//tail

  for (int i = 0; i < array.size(); i++){
    if ( leftSumArray[i] == sum-leftSumArray[i]-array[i+1] ){
      return true;
    }
  }

  return false; 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T = 0;
    int N = 0;
    vector<int> inputArray;
    int num = 0;
    cin >> T;
    for (int i = 0; i < T; i++){
      cin >> N;
      inputArray.clear();
      for (int j = 0; j < N; j++){
       cin >> num;
       inputArray.push_back(num);
      }
      cout << (Sherlock(inputArray)==true)?"YES":"NO" << endl;
    } 
    return 0;
}
