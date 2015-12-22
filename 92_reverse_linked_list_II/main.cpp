//Solution:
//For Example, consider the following linked list:
//head->1->2->3->4->5->6->7->NULL
//We use a sliding window [pred, curr, succ] to process the reversion
//the predeccessor of the first item in the target sublist is stored in <frontas>
//e.g. if we want to reverse [2,5]
//we then slide the window from the first item
//when curr == m, we store the frontas
//when n >= curr > m, we reverse the pointer by letting curr->next = prev
//when curr > n, we stop iteration and adjust the connection as follows:
//if head->|1........n|->n+1->...->NULL
//    then head = n, head->next = n+1
//if head->...->m-1->|m,...,n|->n+1->... (m != 1)
//    then m-1->next->next = n+1, m-1->next = n
//Definition for singly-linked list.

#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //create sliding windows
        ListNode* pred = NULL;
        ListNode* curr = head;
        ListNode* succ = NULL;
        
        int counter = 1;
        
        if ( curr != NULL ){
            succ = curr->next;
        }
        
        //front and end
        ListNode* frontas = NULL;
        ListNode* end = NULL;
        
        //iterate the sliding window
        while( curr != NULL ){
            if ( counter == m ){
                //if the curr pointer is at the starting point, record its previous pointer
                frontas = pred;

            }
            else if ( counter > m && counter <= n ){
                //if the curr pointer is at the target substring, reverse their pointers
                curr->next = pred;

            }
            else if ( counter > n ) {
                break;
            }
            //iterate pointer
            pred = curr;
            curr = succ;
            if ( succ != NULL){
                succ = succ->next;
            }
            counter++;

        }
        if ( frontas == NULL ){
            //if frontas == null the first element in the target substring is the head
            head->next = curr;
            head = pred;
        }
        else {
            frontas->next->next = curr;
            frontas->next = pred;
        }
        return head;
    }
};

int main(){
  ListNode* test = new ListNode(1);
  ListNode* iter = test;
  for (int i = 2; i < 10; i++){
    iter->next = new ListNode(i); 
    iter = iter->next;
  }
  ListNode* display_ptr = test;
  cout << "Current List" << endl;
  while ( display_ptr != NULL ){
    cout << display_ptr->val << " ";
    display_ptr = display_ptr->next;
  }

  //test reversing function
  Solution sol;
  ListNode* reversed_head = sol.reverseBetween(test,2,4);
  cout << "Reversed List:" << endl;
  ListNode* display_ptr_r = reversed_head;
  while ( display_ptr_r != NULL ){
    cout << display_ptr_r->val << " ";
    display_ptr_r = display_ptr_r->next;
  }
  

  return 0;
}
