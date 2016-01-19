#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


class DisjointSet{
 public:
   vector<int> parent;
   vector<int> setSize;

   DisjointSet(int n){
     parent = vector<int>(n,0);
     setSize = vector<int>(n,1);
     //init
     for (int i = 0; i < parent.size(); i++){
       parent[i] = i;
     }
   }

   void setUnion(int i, int j){

     if (setSize[i] >= setSize[j]){
       parent[j] = setFind(parent[i]); 
       setSize[parent[j]]++;
       setSize[j] = setSize[parent[i]];
     } 
     else {
       parent[i] = setFind(parent[j]);
       setSize[parent[i]]++;
       setSize[i] = setSize[parent[i]];
     }

   }
   int setFind(int i){
     while (parent[i] != parent[parent[i]]){
       parent[i] = setFind(parent[i]);
     }
     return parent[i];
   }

   int countSets(){
     int count = 0;
     int prev = -1;
     for (int i = 0; i < parent.size(); i++){
       if (prev != parent[i]){
         count++;
       } 
       prev = parent[i];
     }
     return count;
   }
};

int main() {
    int N = 0;
    vector<pair<int,int> > edges;
    string line;
    cin >> N;
    //input
    for (int i = 0; i < N; i++){
      cin >> line;
      for (int j = 0; j < line.length(); j++){
        if (line[j] == 'Y')
        edges.push_back(make_pair(i,j));
      }
    }

    //Disjoint Set
    DisjointSet ds(N);

    for (int i = 0; i < edges.size(); i++){
      ds.setUnion(edges[i].first,edges[i].second);
    }

    cout << ds.countSets() << endl;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

