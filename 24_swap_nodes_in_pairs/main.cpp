//Using fakeHead will make your life easier,
//Don't forget to check NULL when procceding
#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if (!head || !head->next){
        return head;
      }
      ListNode* fakeHead = new ListNode(0);
      fakeHead->next = head;
      ListNode* r = fakeHead;
      ListNode* p = head;
      ListNode* q = head->next;

      while (q != NULL){
        p->next = q->next;
        r->next = q;
        q->next = p;
        r = p;
        p = p->next;
        if (p){//Don't forget to check if p is NULL
          q = p->next;
        }
        else{
          q = NULL;
        }
      }
      return fakeHead->next;
    }
};

int main(){
  return 0;
}
