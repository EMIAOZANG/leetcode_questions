#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
      map<int,int> q;
      vector<int> primes({2,3,5});
      for (int i = 0; i < primes.size(); i++){
        q.insert(make_pair(primes[i],1));
      }
      map<int,int>::iterator it;
      map<int,int>::iterator smallest_key;
      int smallest_val = ~(1<<31);
      while (n > 0){
        for (it = q.begin(); it != q.end(); it++){
          if ((it->second)*(it->first) < smallest_val){
            smallest_val = ((it->second)*(it->first));
            smallest_key = it;
          } 
        }
        smallest_key->second = ;


        }
      }


        
    }
};

int main(){
  return 0;
}
