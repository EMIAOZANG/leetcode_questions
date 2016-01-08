//Classic Prime Number Problem:
//Prime Number Factorial Theorem: Any number, if not prime, can ben decomposed as a product of prime numbers, therefore we don't need to check every 1,...,sqrt(n), instead, we only check prime factors
//Time Complexity: O(|prime(sqrt(n))|*n)
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
      vector<int> primes(1,2);
      if (n <= 2){
        return 0;
      } 

      for ( int i = 3; i < n; i++){
        for (int j = 0; j <= primes.size(); j++){
          if (i % primes[j] == 0){
            break;
          }
          else if (primes[j] > sqrt(i)){
            primes.push_back(i);
            break;
          }
        }
      }
      return primes.size();
    }
};


int main(){
  Solution sls;
  for (int i = 0; i < 50; i++){
    cout << i << " " <<  sls.countPrimes(i) << endl;
  }
  return 0;
}
