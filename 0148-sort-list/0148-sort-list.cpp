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
    ListNode* findMiddle(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while( l1!=nullptr && l2!=nullptr){
            if(l1->val<l2->val){
                temp->next=l1;
                temp=l1;
                l1=l1->next;
            }else{
                temp->next =l2;
                temp=l2;
                l2=l2->next;
            }
        }
        if(l1)
            temp->next=l1;
        else
            temp->next=l2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* middle=findMiddle(head);
        ListNode* leftHead=head;
        ListNode* rightHead=middle->next;
        middle->next=nullptr;
        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);
        return merge(leftHead,rightHead);
    }
};