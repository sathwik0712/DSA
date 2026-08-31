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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if( head->next->next==NULL)
            return{-1,-1};
        vector<int>res={-1,-1};
        int minDist=INT_MAX;
        ListNode* temp=head->next;
        ListNode* prev=head; 
        int CurrIndex=1;
        int PrevCritical=0,FirstCritical=0;
        //first critial pts
        while(temp->next!=NULL){
            if((temp->val>temp->next->val && temp->val>prev->val) ||
               (temp->val<temp->next->val && temp->val<prev->val)){
                if(PrevCritical==0){
                    PrevCritical=CurrIndex;
                    FirstCritical=CurrIndex;
                }else{
                    minDist=min(minDist,CurrIndex-PrevCritical);
                    PrevCritical=CurrIndex;
                }
            }
            CurrIndex++;
            prev=temp;
            temp=temp->next;
        }
        if(minDist!=INT_MAX){
            int maxDist=PrevCritical-FirstCritical;
            res={minDist,maxDist};
        }
        return res;
    }
};