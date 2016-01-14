//Extending Moore's voting algorithm to more generic case, using ideas from tetrix tower
//Detailed Explanation here:
//http://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/
//
//Time Complexity: O(nk)
//Space Complexity: O(k), in this problem k=3
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> findKMajorElement(vector<int>& nums,int k){
      vector<int> kMajorElements;
      map<int,int> tetrixTower; 
      for (int i = 0; i < nums.size(); i++){
        if (tetrixTower.empty()) {
          //if the stack tower is empty, insert the value
          tetrixTower.insert(make_pair(nums[i],1));
        }
        else {
          map<int,int>::iterator it = tetrixTower.find(nums[i]);
          if (it != tetrixTower.end()){
            //current element in the tower
            (it->second)++;
          }
          else {
            if (tetrixTower.size() < k-1){
              //there are still empty space in the tower
              tetrixTower.insert(make_pair(nums[i],1));
            }
            else {
              for (it = tetrixTower.begin(); it != tetrixTower.end(); it++){
                (it->second)--;
                if (it->second == 0){
                  //if the count is reduced to 0, delete the element
                  tetrixTower.erase(it);
                }
              }
            }
          }
        }
      }
      //clear the count of elements that remained in the tower
      map<int,int>::iterator it = tetrixTower.begin();
      for (it = tetrixTower.begin(); it != tetrixTower.end(); it++){
        it->second = 0;
      }

      //counting occurences
      for (int i = 0; i < nums.size(); i++){
        it = tetrixTower.find(nums[i]);
        if (it != tetrixTower.end()){
          it->second++;
        }
      }
      
      //returning numbers
      for (it = tetrixTower.begin(); it != tetrixTower.end(); it++){
        if (it->second > nums.size()/k){
          kMajorElements.push_back(it->first);
        }
      }
      return kMajorElements;
    }

    vector<int> majorityElement(vector<int>& nums) {
        return findKMajorElement(nums,3);
    }
};

int main(){
  int A[] = {2,2,2,2,1,1,1,3,3};
  vector<int> a(A,A+9);
  Solution sls;
  sls.majorityElement(a);
  return 0;
}
