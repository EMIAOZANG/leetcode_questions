//Cycle detection in linked list, needs to find the starting node of the cycle
//consider this:
//0->1->2->3->4->5->6
//         ^        |
//         |________|
//
//|---l----|D-|
//first use fast and slow pointers to find the meeting node
//let the steps be k
//then we have 2k-k = nr
//we also have l = k-D = nr-D
//therefore l = (n-1)r + (r-D)
//and since r-D is the steps that is needed to go from meeting point 4 back to the starting point, therefore, we could use two pointers, one starting from the head, one start from the meeting point, the first meeting point is the start of the cycle
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
      if (head != NULL){
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && slow != NULL){
          fast = fast->next;
          if (fast != NULL){
            fast = fast->next;
          }
          else return NULL;
          slow = slow->next;
          if (slow == fast){
            //gotcha!
            fast = head;
            while (slow != fast){
              slow = slow->next;
              fast = fast->next;
            }
            //when fast and slow meet each other again, they will meet at the start point
            return slow;
          }
        }


      }
      return NULL;


    }
};

int main(){
  return 0;
}
