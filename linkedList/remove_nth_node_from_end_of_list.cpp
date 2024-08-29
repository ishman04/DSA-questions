#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
  struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int k=0;
        while(temp){
            k++;
            temp=temp->next;
        }
        if(k==1) return NULL; 
        int m=k-n;
        if(m==0) return head->next;
        temp=head;
        int ans=0;
        while(temp){
            ans++;
            if(ans==m){
                temp->next=temp->next->next;
                break;
            }
            else{
                temp=temp->next;                
            }
        }
        return head;
    }
};