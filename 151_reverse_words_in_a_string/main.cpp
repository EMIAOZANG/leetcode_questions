/*
 * Proceed with care!
 * 1. How would you eliminate redundant spaces
 * 2. Don't forget leading and ending spaces
 * 3. Reverse the entire string, then reverse each word using two pointers k, p. k traces the head of either a word or a continuous spaces, p traces the end
 * 4. Take care of how would you resetting k with p, espiecially when after removing spaces.
 *
 * Space Complexity: O(1)
 *
 * NOTE: If there is no O(1) space limit, it could be easily solved by using a deque of string
 */
#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if (s.length() < 1) {
            return;
        }
        
        int i = 0;
        int j = s.length() - 1;

        
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        cout << s << endl;

        int k = 0;
        while (k < s.length()) {
          int p = k;
          if (s[k] != ' '){
            while (p < s.length() && s[p] != ' '){
              p++; //find the end of word
            }
            reverse(&(s[k]), &(s[p]));
            cout << k << "," << p << endl;
          }
          else {
            while (p < s.length() - 1 && s[p + 1] == ' '){
              p++;
            }
            s.erase(k, p - k); 
            p -= p - k;
            p++; //recalibrate p
          }
          k = p;
        }
        //remove leading and ending spaces
        k = 0;
        for (k = 0; k < s.length() && s[k] == ' '; k++){}
        s.erase(0, k);
        for (k = s.length()-1 ; k >= 0 && s[k] == ' '; k--){}
        s.erase(k + 1); //erase from k

    } 
};

int main(){
  string S = "the sky is   blue";
  
  while (getline(cin, S)){
    Solution sls;
    sls.reverseWords(S);
    cout << S << "," << S.length() << endl;
  }
  return 0;
}
