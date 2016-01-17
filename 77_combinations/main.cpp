#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void search(vector<vector<int> >& result, vector<int>& curr, int start, const int n, const int k){
      curr.push_back(start);
        if (curr.size() == k){
          result.push_back(curr);
        } 
        else {
          for (int i = start+1; i <= n; i++){
            search(result,curr,i,n,k);
          }
        }
      curr.pop_back();
    }
    
    vector<vector<int> > combine(int n, int k) {
      vector<int> temp;  
      vector<vector<int> > res;
      for (int i = 1; i <= n; i++){
        search(res,temp,i,n,k);
      }
      return res;
    }
};

int main(){
  Solution sls;
  return 0;
}
