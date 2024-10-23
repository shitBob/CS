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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) 
        return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        do 
        {
            if (fast==NULL || fast->next==NULL)
            return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }while (fast!=slow);
        fast=head;
        while (fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;

        
    }
};