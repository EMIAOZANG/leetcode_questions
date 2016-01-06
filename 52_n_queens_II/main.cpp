//Classic DFS+Backtracking
//The key is to figure out how to detect invalid positions
//We have to consider 3 cases:
// 1. columns: this is trivial
// 2. left diagonal line: note that for a n*n chess board, we could use a 2n-1 array to monitor the state of each diagonal line, e.g.
//     \ \ \ \
//      . . X .
//     \ \ \ \ \
//      . . . .
//     \ \ \ \ \
//      . . . .
//     \ \ \ \ \
//      . . . .
//       \ \ \ \
//        0 1 2 3 4 5 6
// Label them from left to right, then we can compute the index of left diagonal line corresponding to any point (i,j) as follows:
//     indexLeftDiagonal[i,j] = (i+j)+n-1
// 3. Similar to 2., we can construct a 2n-1 array for right diagonal and compute the index as follows:
//     indexrightDiagonal[i,j] = (j-i)+n-1
//We do NOT need to consider rows because each time we will be searching different rows.
//
//To accelerate the validation of occupancy, we use 3 unsigned int (cols,leftDiag,rightDiag) to store as bitsets to store the current state
//Unsigned int is enought to deal with chess board under 64*64

#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

class checkBoard{
    public:
    //Boolean array to store current occupancy state
    unsigned int cols;
    unsigned int leftDiag;
    unsigned int rightDiag;
    int size;
    
    checkBoard(int n):size(n),cols(0),leftDiag(0),rightDiag(0){}
    
    bool isOccupied(unsigned int i, unsigned int j){
        return (((1 << j) & cols) || ((1 << (j-i+size-1)) & rightDiag) || ((1 << (j+i+size-1)) & leftDiag )); //cols occupied || leftDiag occupied || rightDiag Occupied
    }
    
    void insert(unsigned int i, unsigned int j){
        //place the queen at i,j and update checkerboard occupancy status
        cols |= (1 << j);
        leftDiag |= (1 << (i+j+size-1));
        rightDiag |= (1 << (j-i+size-1));
    }
    
    void remove(unsigned int i, unsigned int j){
        //remove the queen at i,j and update
        cols &= ~(1 << j);
        leftDiag &= ~(1 << (i+j+size-1));
        rightDiag &= ~(1 << (j-i+size-1));
    }
};

class Solution {
    public:
    
    void DFS(checkBoard& c, int row, int& s){
        if (row >= c.size){
            s++;
            return;
        }
        //recursively search possible configurations
        for ( int i = 0; i < c.size; i++ ){
            if (!c.isOccupied(row,i)){
                c.insert(row,i);
                DFS(c,row+1,s);
                c.remove(row,i);
            }
        }
    }
    
    int totalNQueens(int n) {
        if ( n == 0 ){
            return 0;
        }
        int numSolutions = 0;
        checkBoard C(n);
        DFS(C,0,numSolutions);
        return numSolutions;
        
    }
};

//Test Only
int main(){
    int N = 0;
    Solution sls;
    while ( cin >> N){
        cout << sls.totalNQueens(N) << endl;
    }
    return 0;
}

