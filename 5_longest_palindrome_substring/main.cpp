/*
 * Think first what Palindrome means:
 * 1. "aaaaaaa", which is a substr of continuous duplicates
 * 2. "abbbbbbba", which is a substr with symmetrical chars wrapped around duplicate substrs
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
        int start_pos = 0;
        int max_len = 1;
        int i = 0;
        while (i < s.length() - max_len / 2) {
            int j = i;
            int k = i;
            //skip duplicates
            while (k < s.length() - 1 && s[k] == s[k + 1]) {
                k++;
            }
            //set starting i for next round
            i = k + 1;
            while (j > 0 && k < s.length() - 1 && s[k + 1] == s[j - 1]){
                k++;
                j--;
            }
            int curr_len = k - j + 1;
            //update longest substr
            if (curr_len > max_len) {
                max_len = curr_len;
                start_pos = j;
            }
        }
        return s.substr(start_pos, max_len);
    }
};
