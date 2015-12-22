//Very classic heaq application problem. Use a max heap to store the smaller half of the data, and a min heap to store the upper half, and keep the two heap balanced,
//therefore, if the total size is odd, then the median is the top element of the larger heap, else the median is the mean of the two top values.
#include <queue>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MedianFinder {
public:
    
    priority_queue<int, vector<int> > max_q;
    priority_queue<int, vector<int>, greater<int> > min_q;
    

    // Adds a number into the data structure.
    void addNum(int num) {
      if (max_q.empty() && min_q.empty()){
        max_q.push(num);
      }
      else{
        if (max_q.size() >= min_q.size()){
          if (num < max_q.top()){
            //move the top of max heap to the min heap
            min_q.push(max_q.top());
            max_q.pop();
            max_q.push(num);
          }
          else {
            min_q.push(num);
          }
        }
        else {
          if (num > min_q.top()){
            //move the min top to the max heap
            max_q.push(min_q.top());
            min_q.pop();
            min_q.push(num);
          }
          else {
            max_q.push(num);
          }
        }
      }
     
        
    }

    // Returns the median of current data stream
    double findMedian() {
      if ((max_q.size() + min_q.size())%2 == 0 ){
        return double((max_q.top() + min_q.top()))/2;
      } 
      else {
        return (max_q.size()>=min_q.size())?max_q.top():min_q.top();
      }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
//

int main(){
  MedianFinder mf;
  mf.addNum(2);
  cout << ((!mf.max_q.empty())?mf.max_q.top():-1) << " " << ((!mf.min_q.empty())?mf.min_q.top():-1) << " " << mf.findMedian() << endl;
  mf.addNum(3);
  cout << ((!mf.max_q.empty())?mf.max_q.top():-1) << " " << ((!mf.min_q.empty())?mf.min_q.top():-1) << " " << mf.findMedian() << endl;
  mf.addNum(4);
  cout << ((!mf.max_q.empty())?mf.max_q.top():-1) << " " << ((!mf.min_q.empty())?mf.min_q.top():-1) << " " << mf.findMedian() << endl;
  mf.addNum(1);
  cout << ((!mf.max_q.empty())?mf.max_q.top():-1) << " " << ((!mf.min_q.empty())?mf.min_q.top():-1) << " " << mf.findMedian() << endl;
  mf.addNum(7);
  cout << ((!mf.max_q.empty())?mf.max_q.top():-1) << " " << ((!mf.min_q.empty())?mf.min_q.top():-1) << " " << mf.findMedian() << endl;
  mf.addNum(5);
  cout << ((!mf.max_q.empty())?mf.max_q.top():-1) << " " << ((!mf.min_q.empty())?mf.min_q.top():-1) << " " << mf.findMedian() << endl;

  return 0;
}
