#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*slow = head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            if(fast->next==slow) return true;
            fast=fast->next->next;
            slow=slow->next;
        }
        return false;
    }
};