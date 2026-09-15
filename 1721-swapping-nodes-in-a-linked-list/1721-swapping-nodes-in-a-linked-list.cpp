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
    ListNode* swapNodes(ListNode* head, int k) {
        int count=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        temp=head;
        int first=0,second=0,cnt=1;
        for(int i=0;i<count;i++){
            if(cnt==k)
                first=temp->val;
            if(cnt==count-k+1)
                second=temp->val;
            temp=temp->next;
            cnt++;
        }
        temp=head;
        cnt=1;
        for(int i=0;i<count;i++){
            if(cnt==k)
                temp->val=second;
            if(cnt==count-k+1)
                temp->val=first;
            temp=temp->next;
            cnt++;
        }
        return head;
    }
};