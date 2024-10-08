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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* fast=head->next->next;
        ListNode* tail=head->next;
        ListNode* temp=head;
        
        while(fast!=NULL){
            ListNode* helper= temp->next;
            temp->next=fast;
            tail->next=fast->next;
            fast->next=helper;
             tail=tail->next;
            if(tail!=NULL) fast=tail->next; else return head;
            temp=temp->next; 
        }
        return head;
    }
};