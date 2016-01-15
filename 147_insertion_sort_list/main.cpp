//swap value method, easy but slow
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      if (head == NULL){
        return NULL;
      }
      if (head->next == NULL){
        return head;
      }

      ListNode* sortedPtr = head;
      ListNode* currPtr = head->next;

      while (currPtr != NULL){
        sortedPtr = head;
        while (sortedPtr != currPtr && sortedPtr->val < currPtr->val){
          sortedPtr = sortedPtr->next;
        }
        //swap two nodes
        
        while (sortedPtr != currPtr){
          swap(sortedPtr->val,currPtr->val);
          sortedPtr = sortedPtr->next;
        }
        currPtr = currPtr->next;
      }
      return head;
    }
};
