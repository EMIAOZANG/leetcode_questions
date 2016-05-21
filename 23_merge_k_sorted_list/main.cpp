/*Priority Queue Merging
1. Use a pseudo head
2. Use a priority queue to store the pointers
3. Check for nullptrs

One good thing here is that we don't need to maintain a pointer for each list, we only need to check the end of lists and keep track of the next node of current queue top as well as adding non-null pointers into the queue.

Time Complexity: O(N)
Space Complexity: O(N)

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class nodeCompare {
public:
    bool operator() (ListNode* a, ListNode* b) {
        return a -> val > b -> val;
    }
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    
        ListNode* merged_phead = new ListNode(0);
        ListNode* p = merged_phead;
        priority_queue<ListNode*, vector<ListNode*>, nodeCompare> pq;
        // vector<ListNode*> ptrs;
        // for (int i = 0; i < lists.size(); i++) {
        //     ptrs.push_back(lists[i])
        // }
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        
        while (!pq.empty()) {
            ListNode* top_node = pq.top();
            ListNode* top_next = top_node -> next; //stage the next node
            pq.pop();
            p -> next = top_node;
            p = p -> next;
            if (top_next != NULL) {
                pq.push(top_next);  //insert the current top node in the list to pq
            }
        }
        
        return merged_phead -> next;
    }
};
