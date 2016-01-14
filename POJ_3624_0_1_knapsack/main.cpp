//Classic 0-1 Knapsack problem
//Dynamic Programming Solution:
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
 public:
   void computeMP(vector<vector<short int> >& MP, vector<short int>& V, vector<short int>& P){
     int n_vol = MP.size();
     int n_items = MP[0].size();

     for (int i = 0; i < n_items; i++){
       //init first line, where volume = 0
       MP[0][i] = 0;
     }

     for (int i = 1; i < n_vol; i++){
       for (int j = 0; j < n_items; j++){
         if (V[j] > i){
           //cannot be taken
           MP[i][j] = 0;
         }
         else if (V[j] == i){
           MP[i][j] = P[j];
         }
         else{
           //if j can be taken, find the maximum sum of P[j] and the max value that can be taken with the remaining space
           for (int k = 0; k < n_items; k++){
             if (k == j){
               continue;
             }
             MP[i][j] = max(MP[i][j], MP[i-V[j]][k]+P[j]);
           }
         } 
       }
     }
   }

   int maxValue(int maxV, vector<short int>& V, vector<short int>& P){
     if (maxV <= 0 || P.size() <= 0){
       return 0;
     }
     int items = *(max_element(P.begin(),P.end()));
     vector<vector<short int> > M(maxV,vector<int>(items,0));
     
     computeMP(M,V,P);

     return *(max_element(M[maxV-1].begin(),M[maxV-1].end()));
   }
};
int main(){
  int N = 0;
  int M = 0;
  cin >> N >> M;
  vector<short int> Volume(N,0);
  vector<short int> Price(N,0);
  for (int i = 0; i < N; i++){
    cin >> Volume[i] >> Price[i];
  }
  Solution sls;
  cout << sls.maxValue(M, Volume, Price)<< endl;

  return 0;
}
