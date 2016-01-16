#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      if (head == NULL){
        return NULL;
      }
      if (head->next == NULL){
        return NULL;
      }
      ListNode* fast = head;
      ListNode* slow = head;

      while ( fast != NULL && slow != NULL ){
        fast = fast->next;
        if (fast != NULL){
          fast = fast->next;
        }
        else {
          return NULL;
        }
        slow = slow->next;
        if (fast == slow){
          return slow;
        }
      }
      return NULL;
    }
};

int main(){
  return 0;
}
