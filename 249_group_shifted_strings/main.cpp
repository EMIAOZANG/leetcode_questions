//Simple Idea For This problem:
//1.Each group can be defined by the gaps between each character in the string, e.g.
//     "abz", "bca" is in same group since diff['abz']=="1,1,24"==diff['bca']
//     ps: we use CYCLE DIFFERENCE here, such that 'a'-'b' = 25
//
//2.Create a eigenString for each vector, and then use UNORDERED_MAP to store the key values
//
//Time Complexity: O(N), N is the total length of the string vector
//Space Complexity: O(N)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;


class Solution {
    public:
    vector<vector<string> > groupStrings(vector<string>& strings) {
        //using unordered map as a hashtable
        unordered_map<string,vector<string> > groups;
        
        //compute a eigenstring for each input string
        for (int i = 0; i < strings.size(); i++){
            string eigenString = "";
            cout << strings[i] << endl;
            for (int j = 0; j < strings[i].length()-1; j++){
                eigenString += char((strings[i][j+1]-strings[i][j]+26)%26+'a'); //append diff to eigenString
                //CAUTION: we use (diff+26)%26 to compute the correct cycle diff
            }
            
            //find eigenString in the hashmap
            unordered_map<string, vector<string> >::iterator pos = groups.find(eigenString);
            if (pos == groups.end()){
                //create a new key pair for current string
                vector<string> currentGroup;
                currentGroup.push_back(strings[i]); //append current string to the list
                groups.insert(make_pair(eigenString,currentGroup));
            }
            else {
                //if the eigenString already exists append current string to the existing list
                (pos->second).push_back(strings[i]);
            }
        }
        
        //sort each vector in lexicon order
        vector<vector<string> > groupVector;
        unordered_map<string, vector<string> >::iterator i;
        for (i = groups.begin(); i != groups.end(); i++){
            sort((i->second).begin(),(i->second).end());
            groupVector.push_back(i->second);
        }
        return groupVector;
        
    }
};

int main(){
    string t[] = {"abc","bcd","acef","xyz","az","ba","a","z"};
    vector<string> test(t,t+8);
    Solution sls;
    vector<vector<string> > v = sls.groupStrings(test);
    return 0;
}
