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
        ListNode* temp=head;

        for (int i=0;i<10001;i++)
            if ((temp=temp->next) == NULL)
                return NULL;


        ListNode *l=head;
        ListNode *r=head->next;
        int num  = 0;
        while (l!=r)
        {
            num=0;
           while (num<10001 && l!=r)
           {r=r->next; ++num;}
           if (l==r)
           return l;
            l=l->next;
            r=l->next;
        }
        return l;
       
        
    }
};