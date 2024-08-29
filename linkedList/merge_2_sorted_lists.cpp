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
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prev;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        if(temp1==NULL) return list2;
        if(temp2==NULL) return list1;
        bool flag;
        if(temp1->val<=temp2->val) {flag=true;temp1=temp1->next;prev=list1;}
        else {flag=false;temp2=temp2->next;prev=list2;}
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<temp2->val){
                prev->next=temp1;
                prev=prev->next;
                temp1=temp1->next;
            }
            else{
                prev->next=temp2;
                temp2=temp2->next;
                prev=prev->next;
            }
        }
        if(temp2!=NULL){
            while(temp2!=NULL){
                prev->next=temp2;
                temp2=temp2->next;
                prev=prev->next;
            }
            prev->next=NULL;
        }
        if(temp1!=NULL){
            while(temp1!=NULL){
                prev->next=temp1;
                temp1=temp1->next;
                prev=prev->next;
            }
            prev->next=NULL;
       }
        if(flag == true) return list1;
        return list2;
    }
};