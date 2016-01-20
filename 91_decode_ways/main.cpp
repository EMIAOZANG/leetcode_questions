//Interesting DP problem
//we have following cases to consider:
//1. ij can be merged (ij in (0,26] and i != 0), there are 2 subcases:
//   1) j == 0, then ij could not be separated, (ij) can only appear as a single number, therefore, dW[j] = dW[i]
//   2) j != 0, then ij could be treated as (i)(j) and (ij), hence dW[j] = dW[i]+dW[i-1], dW[i-1] will cover the cases of (ij)
//2. ij cannot be merged, then
//   1) if j == 0, then result must be 0, because you cannot translate 0
//   2) else, then j has no effect to the number of decyphrals, since no merges can be made, hence dW[j] = dW[i]
//Time Complexity: O(n)
//Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
    int numDecodings(string s) {
        if (s.length() == 0){
            return 0;
        }
        vector<int> decodeWays(s.length()+1, 0);
        s.insert(s.begin(),s[0]); // add a fake head to the front of the string
        
        decodeWays[0] = int((s[0]-'0') != 0); //INIT
        decodeWays[1] = int((s[1]-'0') != 0);
        for (int i = 2; i < decodeWays.size(); i++){
            if (decodeWays[i-1] == 0){
                break;
            }
            int ss = stoi(s.substr(i-1,2));
            if (ss == 0){
                decodeWays[i] = 0;
            }
            else {
                if ( ss > 0 && ss <= 26 && s[i-1] != '0' ){
                    //i-1,i can be merged
                    decodeWays[i] += decodeWays[i-1-int(s[i] == '0')];
                    //we also need to check if i-2,i-1 can be merged
                    decodeWays[i] += decodeWays[i-2]*int(s[i] != '0');
                }
                else {
                    //i-1,i can not be merged
                    decodeWays[i] = decodeWays[i-1]*int(s[i] != '0');
                }
                

            }
            cout << decodeWays[i] << endl;
        }
        return *(decodeWays.rbegin());
        
    }
};

int main(){
    string S = "101";
    Solution sls;
    cout << sls.numDecodings(S) << endl;
    return 0;
}
