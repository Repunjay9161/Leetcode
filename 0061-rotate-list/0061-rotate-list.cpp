/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return head;
      int c=0;
       ListNode* temp =head;
       while(temp!=nullptr){
        c++;
        temp=temp->next;
       }
       int i= k%c;
       ListNode* pre =head;
       temp=head;
       int j=c-i;
       int count =0;
       while(count<j){
          pre=temp;
        temp=temp->next;
          count++;
       }
       if(temp!=nullptr){
        ListNode* x =temp;
         while(temp->next!=nullptr){
           temp=temp->next;
         } 
         pre->next=nullptr;
         temp->next=head;
         head=x;
       }
       return head;
    }
};