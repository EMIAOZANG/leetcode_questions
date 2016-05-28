/*
 * Nim Game, a brain teaser
 *
 * Solution: We could win == the starting number of stones can not be divided by 4
 *
 * Proof:
 * We prove the inverse negation of the conclusion, which is: we could not win iff. n % 4 == 0
 * <==
 * if n % 4 == 0, no matter how many stones I take at each round, let's say i, the guy could always take 4 - i stones, by doing this we will get to the situation where there are only 4 left, then we are dead
 *
 * ==>
 * if we could not win, the competant must be able to take the last 1,2,3 stones, however, if n % 4 != 0, we could always play with the strategy stated above and leave 4 stones at last turn of your friend, then we will win
 */
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
