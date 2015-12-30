//Basic Union-Find Implementation
//Two ways of Union-Find optimization:
//1. Rank Union
//   Keep a setSize array, and always point the parent of the smaller set to the parent of the larger set
//2. Path Compression
//   In find method, trace back recursively to set the parent of any children to the root of the tree
//   using parent[i] = find(parent[i]);

//Time Complexity: Amortized time of Union and Find is O(alpha(n)), alpha(n) is the inverse function of a very steep function, therefore alpha(n) is almost constant

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class DisjointSet {
 public:
   vector<int> parentIndex; //parent index of each element
   vector<int> setSize; //number of elements in each set
   int setCount;

   DisjointSet(int n){
     setCount = n;
     for (int i = 0; i < n; i++){
       parentIndex.push_back(i);
       setSize.push_back(1);
     }
   }

   int Union(int i, int j){
     //disjoint set union
     int iRoot = Find(i);
     int jRoot = Find(j);

     setCount--;
     if (iRoot == jRoot){
       setCount++; //no sets are unioned
       return iRoot;
     }
     if (setSize[iRoot] > setSize[jRoot]){
       parentIndex[jRoot] = iRoot;
       setSize[iRoot] += setSize[jRoot];
       return iRoot;
     }
     else {
       parentIndex[iRoot] = jRoot;
       setSize[jRoot] += setSize[iRoot]; //update set size
       return jRoot;
     }

     return -1;

   }

   int Find(int i){
     //Find an element, using path compression
     if (parentIndex[i] == i){
       return i;
     }
     parentIndex[i] = Find(parentIndex[i]); //recursively look for the parent node
     return parentIndex[i];
   }
};

class Solution {
public:
    int countComponents(int n, vector<pair<int, int> >& edges) {
      //Initialize disjoint set
      DisjointSet graph(n);

      //for each edge, run union method
      for (int i = 0; i < edges.size(); i++){
        graph.Union(edges[i].first,edges[i].second);
      }
      return graph.setCount;
    }
};

int main(){
  return 0;
}
