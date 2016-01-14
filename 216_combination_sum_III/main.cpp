//Backtracking problem, solve carefully using recursions
//
//it is kinda like DFS
//note that you should termintate when following situations occurred:
//1. k == 0, number of remaining positions are exhausted
//
//iteration bounds: 
//1. 1 to min(9,n_remain-curr_num)
//2. For the first digit, you don't have to consider numbers above n-k since there are going to be at least n-k
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    void searchSum(vector<vector<int> >& result, vector<int> curr, int n_remain, int k_remain, int curr_num){
        curr.push_back(curr_num);
        
        if (k_remain <= 0){
            if (n_remain == curr_num){
                result.push_back(curr);
            }
            return;
        }
        
        int maxVal = (n_remain-curr_num > 9)?9:n_remain-curr_num;
        for (int i = curr_num+1; i <= maxVal; i++){
            searchSum(result,curr, n_remain-curr_num, k_remain-1, i);
        }
        curr.pop_back();
    }
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > combinations;
        vector<int> init_combination;
        
        for (int i = 1; i <= n-(k+1)*k/2; i++ ){
            searchSum(combinations,init_combination,n,k-1,i);
        }
        
        return combinations;
    }
};

int main(){
    Solution sls;
    sls.combinationSum3(2,18);
    return 0;
}

