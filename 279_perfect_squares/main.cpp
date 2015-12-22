#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
      //vector that memorizes all square numbers in ascending order
      vector<int> square_numbers;


      //vector that memorizes the min number of perfect square numbers that sum to n
      vector<int> A(n+1,0);
      A.at(1) = 1;
      
      //Compute A[n] using DP
      for ( int i = 1; i <= n; i++ ){
        //first check if i is a perfect square number
        if ( int(sqrt(i)) * int(sqrt(i)) == i ){
          A.at(i) = 1;
          square_numbers.push_back(i);
        }
        else{
          //if not perfect square using dp to find the answwer
	        int temp_min = 2132141234;
	        
	        for ( int j = square_numbers.size()-1; j >= 0; j-- ){
	          temp_min = min(temp_min, 1+A.at(i-square_numbers.at(j)));   //calculate the min value of A[i]
	        }
	        A.at(i) = temp_min;//assign the smallest possible number of perfect squares
        }
      }
      return A.at(n);
    }
};

int main(){

  Solution sls;
//  for ( int i = 0; i < 18; i++){
//    cout << i << "\t" << sls.numSquares(i) << endl;
//  }
  cout << sls.numSquares(12) << endl;

  return 0;
}
