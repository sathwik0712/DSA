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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int count=0, ans=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        ListNode* temp2=head;
        while(temp2!=NULL){
            ans=ans+((temp2->val)*pow(2,count-1));
            count--;
            temp2=temp2->next;
        }
        return ans;
    }
};