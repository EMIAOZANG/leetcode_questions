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
        ListNode* fast = head->next;
        ListNode* slow = head;
        while ( fast != NULL ){
           if ( fast->val != slow->val ){
             slow = slow->next;
           } 
           else{
             //remove all nodes between the fast and slow pointer
           }
           fast = fast->next;
        }
    }
};
