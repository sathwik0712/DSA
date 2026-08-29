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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( head==nullptr || head->next== nullptr)
            return nullptr;
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        ListNode* temp1=head;
        int target=count-n;
        if( target==0){
            head=head->next;
            return head;
        }
        ListNode* prev=NULL;
        while(target!=0){
            prev=temp1;
            temp1=temp1->next;
            target--;
        }
        prev->next=temp1->next;
        delete temp1;
        return head;
    }
};