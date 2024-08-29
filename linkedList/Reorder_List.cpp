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
    ListNode* reverseList(ListNode* &head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* NEXT = NULL;
        while(curr){
            NEXT=curr->next;
            curr->next=prev;
            prev=curr;
            curr=NEXT;
        }
             
   return prev; 
   }
    void reorderList(ListNode* head) {
        ListNode* temp1=head;
        int count=0;
        while(temp1->next!=NULL){
            temp1=temp1->next;
            count++;
        }
        temp1=head;
        int idx=count/2;
        ListNode* temp2=head;
        int idx1=0;
        while(idx1!=idx){
            temp2=temp2->next;
            temp1=temp1->next;
            idx1++;
        }
        temp2=temp2->next;
        temp1->next=NULL;
        temp1=head;
        temp2=reverseList(temp2);
        ListNode* a=temp1;
        ListNode* b = temp2;
        ListNode* c = temp1;
        ListNode* d =temp2;
        while(a!=NULL && b!=NULL){
            c=c->next;
            a->next=b;
            d=d->next;
            b->next=c;
            a=c;
            b=d;
        }
    }
};