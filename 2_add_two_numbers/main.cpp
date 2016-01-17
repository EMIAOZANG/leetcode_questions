#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* p1 = l1;
      ListNode* p2 = l2;

      int sum = 0;
      int advance = 0;
      
      ListNode* pSum = new ListNode(0);
      ListNode* p3 = NULL; 
      ListNode* pSumHead = NULL;

      while (p1 != NULL && p2 != NULL){
        sum = p1->val + p2->val + advance;
        advance = sum / 10;
        sum %= 10;
        pSum->val = sum;

        if (p3 == NULL){
          p3 = pSum; 
          pSumHead = pSum;
        }
        else {
          p3->next = pSum;
          p3 = p3->next;
        }
        pSum = new ListNode(0);

        p1 = p1->next;
        p2 = p2->next;
      }
      while (p1){
        sum = p1->val + advance;
        advance = sum / 10;
        sum %= 10;

        pSum->val = sum;

        if (p3 == NULL){
          p3 = pSum; 
          pSumHead = pSum;
        }
        else {
          p3->next = pSum;
          p3 = p3->next;
        }
        pSum = new ListNode(0);

        p1 = p1->next;
      }
      while (p2){
        sum = p2->val + advance;
        advance = sum / 10;
        sum %= 10;
        
        pSum->val = sum;

        if (p3 == NULL){
          p3 = pSum; 
          pSumHead = pSum;
        }
        else {
          p3->next = pSum;
          p3 = p3->next;
        }

        pSum = new ListNode(0);
        p2 = p2->next;
      }
      //the highest digit advance
      if (advance){
        pSum->val = 1; 
        p3->next = pSum;
      }
      return pSumHead; 
    }
};
