//An Extension to 274: h-Index with Binary Search
//define doc[i] = N-i, which is the number of aritcles has citations >= i
//cite[i], which is the number of citations(sorted in ascending order)
//
//the idea is to find the first element that satisfies:
//    doc[i] <= cite[i]
//therefore we use binary search to search for doc[i] == cite[i]-1/2, and we will get the position that lies just ahead of the first element.  
//
//Time Complexity: O(lgn)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  //Standard binary search
    int binarySearch(vector<int>& v, int& num, int left, int right){
      if (left >= right){
        return left;
      }
      int mid = (left+right)/2;
      if (mid == num){
        return mid;
      }
      if (mid > num){
        return binarySearch(v,num,left,mid-1);
      }
      if (mid < num){
        return binarySearch(v,num,mid+1,right);
      }
    }

    int binaryFind(vector<int>& v, int offset, int left, int right){
      if (left > right){
        return v.size()-right-1;
      }
      int mid = (left+right)/2;
      if (v.size()-mid == v[mid]-offset){
        return v.size()-mid; //return the h value
      }
      if (v.size()-mid > v[mid]-offset){
        return binaryFind(v,offset,mid+1,right);
      }
      if (v.size()-mid < v[mid]-offset){
        return binaryFind(v,offset,left,mid-1);
      }
      return 0; 
    }

    int hIndex(vector<int>& citations) {
      int leftEnd = binaryFind(citations,0.5,0,citations.size()-1);
//      int rightEnd = binaryFind(citations,-1,0,citations.size()-1);
//      return (rightEnd > leftEnd)?rightEnd:leftEnd;
      return leftEnd+1;
    }
};

int main(){
  int a[] = {1,2,3,5,5,5,6};
  vector<int> A(a,a+7);
  Solution sls;
  sls.hIndex(A);
  return 0;
}
