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
    ListNode* reverseList(ListNode* head) {
        ListNode* front =nullptr;
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp!=NULL){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if( head==nullptr || head->next==nullptr)
            return;
        ListNode* first=head;
        ListNode* middle=middleNode(head);
        ListNode* second=middle->next;
        middle->next=nullptr;
        second=reverseList(second);
        while( second!=nullptr){
            ListNode* t1=first->next;
            ListNode* t2=second->next;
            first->next=second;
            second->next=t1;
            first=t1;
            second=t2;
        }
        
    }
};