//Simple pointer deletion problem
//Note that using a pseudo-head will ease your life DRAMATICALLY!
//
//Time Complexity: O(n)
//Space Complexity: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //Using a delayed pointer
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Use a pseudohead to simplify boundary case
        ListNode* phead = new ListNode(-1);
        phead->next = head;
        
        ListNode* delayed = phead;
        ListNode* ptr = head;
        
        int count = 0;
        
        while (ptr != NULL) {
            if (count >= n) {
                delayed = delayed->next;
            }
            ptr = ptr->next;
            count++;
        }
        delayed->next = delayed->next->next;
        return phead->next;
    }
};
