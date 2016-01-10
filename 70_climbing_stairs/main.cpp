//Le Fibonacci!
//You DO NOT need a O(n) vector to keep all results
#include <iostream>
using namespace std;


class Solution {
public:
//el fibonacci!
    int climbStairs(int n) {
        if (n == 0 || n == 1){
            return 1;
        }
        int prev = 1;
        int curr = 1;
        int temp = 0;
        for (int i = 2; i <= n; i++){
            temp = curr;
            curr += prev;
            prev = temp;
        }
        return curr;
    }
};
