//delete duplicates in linked list
//
//Boundary conditions:
//1. fast->next == NULL
//2. !head or !head->next
//3.slow = NULL (when first non-duplicate number is not found)
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if ( head == NULL ){
          return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = NULL;
        bool extFlag = false;

        while ( fast->next != NULL ){
           if ( extFlag || fast->val == fast->next->val ){
             //remove nodes
             if ( slow == NULL ){
               head = fast->next;
             }
             else {
               slow->next = fast->next;
             }
             extFlag = true;
             if ( fast-> val != fast->next->val ){
               extFlag = false;
             }
           }
           else {
             slow = fast;
             
           }
           fast = fast->next;
        }
        if ( extFlag ){
          //remove the last possible node
          if ( slow == NULL ){
            head = fast->next;
          }
          else {
            slow->next = fast->next;
          }
        }
        return head;
    }
};
