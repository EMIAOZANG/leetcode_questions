//Classic Float Number Power Problem
//Using Bit Manipulation could make life easier!
//We only need to compute x, x^2, x^4, ....
//    x^n = x^(n/2) * x^(n/2), if n is even
//        = x^(n/2) * x^(n/2) * x, if n is odd
//
//Now, Consider the binary representation of n;
//e.g. n = 11 , then n(2) = 1011
//and we know x^n = x^8+x^3+x^1
//Therefore, we only need to shift n(2) rightward iteratively till n == 0, and square x every time we shift n, if the last digit of n is 1, we multiply result by x
//Time complexity: O(logn)
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
    public:

    
    double myPow(double x, int n) {

        if ( n < 0 ){
            x = 1.0/x;
            n = -n;
        }
        //compute x**n
        double result = 1;
        while ( n > 0 ){
            if ( (n & 1) != 0 ){
                //if current digit is 1, multiply result by x
                result *= x;
            }
            n >>= 1;
            x *= x; //square x
        }
        return result;
    }
};

int main(){
    Solution sls;
    cout << sls.myPow(2.0,11) << endl;
    return 0;
}
