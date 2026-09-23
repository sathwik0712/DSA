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
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        ListNode* middle=middleNode(temp);
        ListNode* newhead= reverseList(middle->next);
        ListNode* first=head;
        ListNode* second=newhead;
        while(second!=nullptr){
            if(first->val!=second->val){
                reverseList(newhead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseList(newhead);
        return true;
    }
};