//Classic Singly Linked List Node Operation:
//3-Pointer Paradigm
//f: front
//n: now
//b: back
//
//Start Condition: b = NULL, n = head, f = head->next
//  b    n   f
//head-> 1-> 2-> 3-> NULL
//
//End Loop: (f==NULL)
//           b   n   f
//head-> 1-> 2-> 3-> NULL
//
//After Loop: reverse the next pointer of the last node
//n->next = b
//
//Time Complexity: O(n)
//Space Complexity: O(1)
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head){
      if (head == NULL){
        return head;
      }
      ListNode* b = NULL;
      ListNode* n = head;
      ListNode* f = head->next;

      while (f != NULL){
        //if f==NULL, then we just assign head = n
        n->next = b;
        b = n;
        n = f;
        f = f->next;
      }
      n->next = b;  //Don't forget to reverse the last node!!!
      head = n;
      return head;
    }
};
