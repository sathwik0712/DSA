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
    ListNode* KthNode(ListNode* temp,int k){
        k--;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head) {
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* Knode=NULL;
        ListNode* nextNode=NULL;
        ListNode* prev=NULL;
        int cnt=0;
        while(temp!=NULL){
            Knode=KthNode(temp,k);
            if(Knode==NULL){
                if(prev)
                    prev->next=temp;
                break;
            }
            nextNode=Knode->next;
            Knode->next=NULL;
            reverse(temp);
            if(temp==head)
                head=Knode;
            else
                prev->next=Knode;
            prev=temp;
            temp=nextNode;
        }
        return head;
    }
};