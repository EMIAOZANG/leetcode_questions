#include <cmath>
//Variant of OpenJudge 1088 - Ski
//Sort & DP problem
//Let S[i] be the optimal (possible min under constraints) number of candies for i, then:
//S[i] = 1, if Ratings[i-1], Ratings[i+1] >= Ratings[i]
//     = S[i+1], if Ratings[i+1] < Ratings[i] <= Ratings [i-1]
//     = S[i-1], if Ratings[i-1] < Ratings[i] <= Ratings [i+1]
//     = max(S[i-1],S[i+1])+1, if Ratings[i] > Ratings[i-1], Ratings[i+1]
//Then we could compute S[i] from the smallest value
//Time Complexity: O(nlgn + n) = O(nlgn)
//Space Complexity: O(n)

#define INF 2100000000

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <numeric>


using namespace std;

vector<int> elemOpt(vector<int>& array){
  vector<int> optCandies(array.size(),1);
  multimap<int,int> indexMap;
  //sort index by value in ascending order
  for (int i = 1; i < array.size()-1; i++){
    indexMap.insert(make_pair(array[i],i)); 
  }
  multimap<int,int>::iterator i;
  int currentIndex = 0;
  for (i = indexMap.begin(); i != indexMap.end(); i++){
    //compute opt candies
    if (array[(i->second)+1] < i->first){
      optCandies[i->second] = max(optCandies[i->second],optCandies[(i->second)+1]+1);
    }
    if (array[(i->second)-1] < i->first){
      optCandies[i->second] = max(optCandies[i->second],optCandies[(i->second)-1]+1);
    }
  }
  return optCandies;
}

int MinCandies(vector<int>& array){
  if (array.size() == 0){
    return 0;
  }
  vector<int> S(elemOpt(array));
  int sumOpt = 0;
  for (int i = 1; i < S.size()-1; i++){
    sumOpt += S[i];
  }
  return sumOpt;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N = 0;
    vector<int> rating;
    int num = 0;
    cin >> N;
    rating.push_back(INF);
    for (int i = 0; i < N; i++){
      cin >> num;
      rating.push_back(num);
    }
    rating.push_back(INF);
    cout << MinCandies(rating) << endl;

    return 0;
}

