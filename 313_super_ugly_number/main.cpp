#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      set<int> tree;
      tree.insert(1);
      int smallest = 0;
      while (tree.size() != 0 && n > 0){
        smallest = *(tree.begin());
        tree.erase(tree.begin());
        for (int i = 0; i < primes.size(); i++){
          tree.insert(smallest*primes[i]);
        }
        n--;
      }
      return smallest;
    }
};
