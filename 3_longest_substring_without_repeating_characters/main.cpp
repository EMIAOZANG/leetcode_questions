//Application of HashMaps (unordered_map), Use two pointers
//Keep the last seen position of each letter in the HashMap, if letter had never been seen before, Insert a new hash node
//e.g.
//s:   a b b a b c a b c
//Map: 0 1 2 3 4 5 6 7 8
//Iterate through the string for one pass, and keep update startPos to make sure it always stays at a position, where all letters after it were only seen ahead of it (each letter is "fresh" after startPos)
//
//Time Complexity: O(n)
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      //HashMap: (letter, last seen position)
      unordered_map<char,int> letterMap;

      int startPos = -1;
      int endPos = 0;

      int currSubstrLength = 0;
      int maxSubstrLength = 0; 

      while (endPos < s.length()){
        unordered_map<char,int>::iterator it = letterMap.find(s[endPos]);
        if (it != letterMap.end()){
          //repeat found
          startPos = max(it->second, startPos); //if the position is ahead of startPos, don't care about it
          currSubstrLength = endPos - startPos;
          it->second = max(it->second, endPos);
        }
        else {
          //no repeat, insert new map node (current char, last seen position)
          letterMap.insert(make_pair(s[endPos],endPos));
          currSubstrLength++;
        }
        maxSubstrLength = max(maxSubstrLength,currSubstrLength);
        endPos++;
      }
      return maxSubstrLength;
    }
};

