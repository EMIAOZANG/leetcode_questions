/*
Few Points here:

### How do we treat inputs

We remove all leading spaces, and the first non-space char could only be numbers or '+' or '-', (only 1 sign is allowed, e.g. '++' is invalid)

We process the string to the last continuous numerical digit and ignore the rest. e.g. '-0012abc123' is converted to -12

Any overflow values are truncated to INT_MAX or INT_MIN, so we have to check 1 step earlier for potential overflows, note that INT ranges from -2147483648 to 2147483637
*/

#include <limits.h>
#include <string>
using std::string;

class Solution {
public:
    int myAtoi(string str) {
        int num = 0;
        int sign = 1;
        
        int i = 0;
        //remove leading spaces
        while (i < str.length() && str[i] == ' ') {
            i++;
        }
        
        //leading signs
        if (str[i] == '+') {
            i++;
        }
        else if (str[i] == '-'){
            sign = -1;
            i++;
        }
        
        for (; i < str.length(); i++) {
            //stop when we found a non-numeric char
            if (str[i] > '9' || str[i] < '0') {
                return sign * num;
            }
            //check early for overflow
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)) {
                return sign == -1?INT_MIN : INT_MAX;
            }
            num = num * 10 + str[i] - '0';
        }
        return sign * num;
    }
};
