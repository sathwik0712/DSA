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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if( head->next==NULL)
            return head;
        ListNode* temp=head;
        ListNode* next=NULL;
        while(temp->next!=NULL){
            next=temp->next;
            int val=__gcd(temp->val,next->val);
            ListNode* node=new ListNode(val,next); 
            temp->next=node;
            temp=next;
        }
        return head;
    }
};