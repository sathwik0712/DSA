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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        ListNode* end=NULL;
        int count=0;
        while(temp!=NULL){  
            if(count==b){
                end=temp->next;
                break;
            }
            count++;
            temp=temp->next;
        }
        int count2=1;
        temp=list1;
        while(temp->next!=NULL){
            if(count2==a){
                temp->next=list2;
            }else
                temp=temp->next;
            count2++;
        }
        temp->next=end;
        return list1;
    }
};