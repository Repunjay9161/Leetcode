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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp =head;
        int c=0;
        while(temp!=nullptr){
            c++;
            temp=temp->next;
        }
        if(k>c) return head;
        temp=head;
        ListNode* pre=nullptr;
        int total = 0;
        int y=c/k;
        int count =  0; 
        ListNode* l=head;
        ListNode* x=head;
        while(total!=y){
            ListNode* curr=temp->next;
            temp->next=pre;
            pre=temp;
            temp=curr;
            count++;
            if(count==k ){
                total++;
                if(total==1){
                    head=pre;
                }
                if(total>1){
                    x->next=pre;
                     x=l;
                }
                l=temp;
                pre=nullptr;
                count=0;
            }

        }
        if(temp!=nullptr){
            x->next=temp;
        }
        return head;
    }
};