/*
 * This is a classic dynamic order statistics solution using heap, it is particularly designed for large data stream processing
 * 
 * Maintain a MIN HEAP of size k, and insert to the heap only when the current element is greater than the top of the min heap or heap size is smaller than k
 * This would work for the case when n cannot fit into memory but k is smaller than memory size
 *
 * Time complexity: O(nlogk)
 * Space complexity: O(k)
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

      priority_queue<int, vector<int>, greater<int> > min_heap;

      auto it = nums.begin();
      while (it != nums.end()) {
        if (min_heap.size() >= k && *(it) > min_heap.top()) {
          min_heap.pop();
        }

        if (min_heap.size() < k){
          min_heap.push(*(it));
        } 
        it++;
      }
      
      return min_heap.top();
    }
};
