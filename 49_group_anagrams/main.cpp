#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:

    long long eigenValue(const string& s){
      //eigenvalue packet structure:
      //NEG | STRING LENGTH (26->n-2) | 
      long long result = 0;
      for (int i = 0; i < s.length(); i++){
        result |= 1 << int(s[i]-'0'); //multiset up bit counter 
      }
      return result;
    }
    

    vector<vector<string> > groupAnagrams(vector<string>& strs) {
      vector<vector<string> > result; 
      unordered_map<string,multiset<string> > dict;

      unordered_map<string,multiset<string> >::iterator it;

      for (int i = 0; i < strs.size(); i++){
        string eigenStr = strs[i];
        sort(eigenStr.begin(),eigenStr.end());
        it = dict.find(eigenStr);

        if (it != dict.end()){
          (it->second).insert(strs[i]);
        }
        else {
          multiset<string> tempmultiset;
          tempmultiset.insert(strs[i]);
          dict.insert(make_pair(eigenStr,tempmultiset));
          tempmultiset.clear();
        }
      }
      
      //output arrays
      for (it = dict.begin(); it != dict.end(); it++){
        vector<string> tempOut((it->second).begin(),(it->second).end());
        result.push_back(tempOut);
        tempOut.clear();
      }
      return result;
    }

};

int main(){
  return 0;
}
