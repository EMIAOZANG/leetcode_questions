/*
 * DESIGN A BINARY DIVIDER UNIT
 * CAUTION: boundary case -2^32
 *
 * First, we use these formulae to convert neg number to their corresponding pos representation and vice versa:
 *
 * X_pos = ~(X - 1), X is a negative int_32
 * X_neg = ~(X) + 1, X is a positive int_32 
 *
 * -2^32 will remain unchanged by using these 2 formulae, so no need to worry boundary cases
 * Then we cast type int -> unsigned int
 *
 * We also keep track of a negation sign indicator bool neg_flag = (dividend < 0) != (divisor < 0)
 *
 * Then the work flow of a divider is basically ALIGN + SUBTRACT:
 * e.g. (4-bit unsigned)
 * 1111 / 10
 * 1) 10 -> 1000 (ALIGN)
 * 2) 1111 - 1000 (SUBSTRACT) = 111 (MOD), QUOTIENT ++ 
 * 3) if MOD > 1000, we do 2) again, otherwise, we shift 1000 -> 100, and QUOTIENT << 1, Then repeat 2) until we can not make any further substractions (divisor == original divisor and MOD < divisor)
 */
#include <algorithm>
#include <iostream>
using namespace std;
const unsigned int MAX_INT = ~(1 << 31);
class Solution {
public:
    int divide(int dividend, int divisor) {
        //preprocessing
        if (divisor == 0){
            return 0;
        }

        bool neg_de = false;
        bool neg_dr = false;
        if (dividend < 0){
            dividend = ~(dividend - 1); //convert neg to pos, which works well with -2**N
            neg_de = true;
        }
        if (divisor < 0){
            divisor = ~(divisor - 1);
            neg_dr = true;
        }
        unsigned int de = dividend;
        unsigned int dr = divisor;
        
        unsigned int old_dr = dr;
        unsigned int q = 0; //quotient
        unsigned int mod = de;

        //align from right
        while ((dr & (1 << 31)) == 0) {
            dr <<= 1;
        }
        //start dividing
        while (mod >= dr || dr != old_dr) {

            if (mod >= dr) {
                mod -= dr;
                q++;
            }
            else {
                if (dr == old_dr){
                    break;
                }
                dr >>= 1;
                q <<= 1;
            }
        }
        
        //restore to signed_int
        if (neg_de != neg_dr) {
            return (~q) + 1 ; //convert pos unsigned back to neg representation, works with -2**N
        }
        else {
            return int(min(MAX_INT, q)); //if the unsigned result overflowed, truncate it to MAX_INT
        }
    }
};
int main(){
  return 0;
}
