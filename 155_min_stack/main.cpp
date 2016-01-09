//Using double stack, easy

#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> mins;
    stack<int> stk;
    void push(int x) {
        //update vector and top
        stk.push(x);
        //update min
        if (mins.empty() || mins.top() > x){
            mins.push(x);
        }
        else {
            mins.push(mins.top());
        }
    }

    void pop() {
        if (!stk.empty()){
            stk.pop();
            mins.pop();
        }
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return mins.top();
    }
};
