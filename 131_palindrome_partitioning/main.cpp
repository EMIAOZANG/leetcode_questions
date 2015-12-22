//
//  main.cpp
//  leetcode_131
//
//  Created by Jiayi Lu on 12/22/15.
//  Copyright © 2015 Jiayi Lu. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution{
public:
    void computePalindrome(vector<vector<bool> >& P_, string& s){
        for (int i = 0; i < s.length(); i++ ){
            P_[i][i] = true;
            P_[i+1][i] = true;
        }
        for (int k = 1; k < s.length(); k++ ){
            for (int i = 0; i < s.length()-k; i++){
                P_[i][i+k] = P_[i+1][i+k-1] & (s[i] == s[i+k]);
            }
        }
        
    }
    
    void addPartition(vector<vector<string> >& v, vector<vector<bool> >& P_, stack<string>& stk, string& s, int start){
        if (start >= s.length()){
            if (!stk.empty()){
                //pour current stack items to vector
                string* end = &stk.top()+1;
                string* begin = end-stk.size();
                vector<string> current_v(begin,end);
                v.push_back(current_v);
            }
            return;
        }
        //search
        for (int k = 0; k < s.length()-start; k++ ){
            for (int i = start; i < s.length()-k; i++){
                if (P_[i][i+k] == true){
                    stk.push(s.substr(i,k+1));
                    cout << stk.top() << endl;
                    addPartition(v, P_, stk, s, i+k+1);
                    stk.pop();
                }
            }
        }
    }
    vector<vector<string> > partition(string s){
        vector<vector<bool> > P(s.length()+1, vector<bool>(s.length(),true));
        vector<vector<string> > V;
        stack<string> sk;
        
        computePalindrome(P, s);
        addPartition(V, P, sk, s, 0);
        
        return V;
    }
    
};

int main(){
    Solution sls;
    vector<vector<string> > res;
    res = sls.partition("aaaab");
    
    return 0;
}
