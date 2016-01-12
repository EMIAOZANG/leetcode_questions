#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution{
 public:
   void computeNP(int i, int j){

   }
   int numDecompositions(int n){
     vector<vector<int> > NP(n+1,vector<int>(n+1,0));
     for (int i = 0; i <= n; i++){
       NP[i][i] = 1; //no decomposition, n_partitions = 1
       NP[0][i] = 1; 
     }
     for (int i = 1; i <= n; i++){
       for (int j = 1; j <= i/2; j++){
         for (int k = 1; k <= (n-2*j)/2; k++){
           NP[i][j] += NP[n-2*j][k];
         }
         NP[i][j] += 1;
       }
     }
     return accumulate(NP[n].begin(),NP[n].end(),0);
   }
};

int main(){
  int N = 0;
  Solution sls;
  while (cin >> N){
    cout << N << " " << sls.numDecompositions(N) << endl; 
  }
  return 0;
}
