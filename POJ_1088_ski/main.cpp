//Ski Problem: Classic DP
#define INF 2100000000
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
 public:
   multimap<int, pair<int,int> > sortMap(vector<vector<int> >& v){
     //use stl::multimap to sort points in ascending order
     multimap<int,pair<int,int> > m;
     for (int i = 1; i < v.size()-1; i++){
       for (int j = 1; j < v[i].size()-1; j++){
         m.insert(make_pair(v[i][j],make_pair(i,j)));
       }
     }
     return m;
   }

   void computeLP(vector<vector<int> >& v, vector<vector<int> >& lp, int i, int j){
     //compute LP[i,j]
     for (int row = i-1; row <= i+1; row += 2){
       for (int col = j-1; col <= j+1; col += 2){
         if (v[row][col] < v[i][j]){
           lp[i][j] = max(lp[i][j],lp[row][col]+1); //update the lp in-place 
         } 
       }
     }
   }

   int longestDescendingPath(vector<vector<int> >& v){
     if (v.size() == 0){
       return 0;
     }
     //Initialize LongestPath matrix
     vector<vector<int> > LP(v.size(),vector<int>(v[0].size(),0));

     //compute the sorted list of points
     multimap<int, pair<int,int> > M(sortMap(v));
     multimap<int, pair<int,int> >::iterator i;
     for (i = M.begin(); i != M.end(); i++){
       //compute LP for each point
       computeLP(v,LP,(i->second).first,(i->second).second); //update LP[i,j]
     }
     int maxLength = 0;
     for (int i = 1; i < LP.size()-1; i++ ){
       for (int j = 1; j < LP[0].size()-1; j++){
         if (LP[i][j] > maxLength){
           maxLength = LP[i][j];
         }
       }
     }
     return maxLength;
   }


};

int main(){
  int rows = 0;
  int cols = 0;

  cin >> rows >> cols;

  vector<vector<int> > V(rows+2,vector<int>(cols+2,INF));
  for (int i = 1; i < V.size()-1; i++){
    for (int j = 1; j < V[0].size()-1; j++){
      cin >> V[i][j];
    }
  }

  Solution sls;
  cout << sls.longestDescendingPath(V) << endl;

  return 0;
}
