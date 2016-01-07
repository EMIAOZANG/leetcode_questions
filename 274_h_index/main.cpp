//Sorting Problem
//H-Index: given N documents, there are EXACTLY h documents with score AT LEAST h, and all the rest
//have score NO MORE than h,
//
//therefore by sorting documents score in descending order, e.g.
//
//SCORE DOCS_COUNT
//6     1
//5     2
//4     3
//4     4
//3     5
//
//we only need to find the last element where SCORE >= DOCS_COUNT
//
//Time Complexity: O(nlgn)
//Space Complexity: O(n)
//
//**********O(n) Solution***********
//Consider the following facts:
//1.h index will NOT exceed the size of the vector
//2.all citations bigger than the size can be regarded as same as vector size
//
//Hence we could follow the idea similar to COUNTING SORT, we only need to find the last h score that has h docs above it, thus reducing the time complexity to O(n)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndexSlow(vector<int>& citations) {
      sort(citations.begin(),citations.end(),greater<int>()); 
      int i = 0;
      for (i = 1; i <= citations.size() && citations[i-1] >= i; i++){}
      return i-1;
    }

    //Fast hIndex algorithm
    int hIndex(vector<int>& citations){
      //counting sort
      vector<int> record(citations.size()+1,0);
      for (int i = 0; i < citations.size(); i++){
        if (citations[i] > citations.size()){
          record[citations.size()]++;
        }
        else {
          record[citations[i]]++;
        }
      }
      //iterate through record to find the first citation score that statisfies that has h docs above
      int sumDocs = citations.size();
      int j = 0;
      for (j = 0; j < record.size(); j++){
        sumDocs -= record[j];
        if (sumDocs <= j){
          return j;
        }
      }
      return 0; 
    }
};

int main(){
  return 0;
}
