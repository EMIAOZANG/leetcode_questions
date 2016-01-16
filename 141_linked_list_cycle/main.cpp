//Classic Linked list cycle detection using slow-fast pointers, make sure you check the availability of next pointer everytime you wanna move the pointer, if NULL is touched just return false
//Time complexity: O(n)
//Space Complexity: O(1)
//
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
      if (head != NULL){
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && slow != NULL){
          fast = fast->next;
          if (fast != NULL){
            fast = fast->next; //Don't forget to return false when the end of linked list is touched
          }
          else return false;
          slow = slow->next;
          if (fast == slow){
            return true;
          }
        }

      }  
      return false;
    }
};

int main(){
  return 0;
}
