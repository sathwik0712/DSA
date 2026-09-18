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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head== nullptr || head->next==nullptr)
            return head;
        ListNode* prev=head;
        ListNode* temp=head->next;
        while(temp!=nullptr){
            if(prev->val == temp->val){
                ListNode* dup=temp;
                prev->next=temp->next;
                temp=temp->next;
                delete dup;
            }
            else{
            prev=temp;
            temp=temp->next;
            }
        }
        return head;
    }
};