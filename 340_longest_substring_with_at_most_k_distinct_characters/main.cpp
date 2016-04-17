/*
 * Classic Two Pointers problem
 *
 * e.g.
 * e b e c a
 * 0 1 2 3 4
 * Maintain a HashTable for counts of unique characters:
 * Use 2 pointers, starting from left = -1, right = 0
 * and move right ptr towards right, update the count table
 * after we moved right
 * if we found the size of the HashTable > k:
 * we have to move the left to the right by one unit
 * 
 * later, we update the max length of the substr
 * 
 * Time Complexity: O(n), cuz u never go back
 * Space Complexity: O(n), when all letters are unique
 *
 */

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
      if (s.length() == 0 || s.length() <= k){
        return s.length();
      }
      int left = -1;
      int right = 0;

      int max_length = 0;

      map<char, int> dict;

      while (left < right && right < s.length()) {
        //update max_length if the condition is satisfied

        auto it = dict.find(s[right]);
        if (it != dict.end()) {
          (it -> second)++;
        }
        else {
          dict.insert(make_pair(s[right], 1));
        }
        
        if (dict.size() > k){
          left++;
          auto it_left = dict.find(s[left]);
          if (it_left != dict.end()){
            if (it_left -> second > 0){
              (it_left -> second)--;
            }
            if (it_left -> second == 0){
              dict.erase(it_left);
            }
            left++;
          }
              
        }
        cout << s[left] << "," << s[right] << ", " << dict.size() << endl;
    
        if (dict.size() <= k){
          max_length = max(max_length, right-left);
        }
        
        right++;
      }
      return max_length;
    }
};
