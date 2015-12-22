/* IDEA: Make a assistant list and append all nodes smaller than x to it, e.g.
 *    Original List: head->1->2->8->7->3->6->5->4->NULL
 *    small_head->[header]->1->2->3->NULL
 *    head->8->7->6->5->4->NULL
*/
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    ListNode* partition(ListNode* head, int x) {
      //cursor pointers
      ListNode* short_head = new ListNode(x);
      ListNode* j = short_head;
      
      //iterate the list and update the small list
      ListNode* i_front = NULL;
      ListNode* i = head;
      while ( i != NULL ){
        if (i->val < x){
          //Drop from original list and append to the smaller_list
          if (i == head){
            head = i->next;
          } 
          else{//If current node who is smaller than x is not the head, then replace i->front->next with i->next
            i_front->next = i->next;
          }
          j->next = i;
          j = j->next;
        }
        else {//If i->val >= x, iterate i only
          i_front = i;
        }
          i = i->next;
      }

      //Concatenate two lists
      ListNode* new_head = short_head;
      j->next = head;

      return short_head->next;

      
    }
};

int main(){

  return 0;
}
