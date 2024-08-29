#include<bits/stdc++.h>
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
    struct  cmp{
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* tempo=new ListNode(0);
        ListNode* temp=tempo;
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
           if(lists[i]) pq.push(lists[i]);
        }
        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            temp->next=ele;
            temp=temp->next;
            
            if(ele->next!=NULL){
                ele=ele->next;
                pq.push(ele);
            }
        }
        return tempo->next;
    }
};