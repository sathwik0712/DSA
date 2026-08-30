class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=0,maxi=0;
        for(int i=1;i<nums.size();i++){
            if( nums[i]>nums[maxi])
                maxi=i;
            if(nums[i]<nums[mini])
                mini=i;
        }
        int front=max(mini+1,maxi+1);
        int back=nums.size()-min(mini,maxi);
        int both=min(mini+1,maxi+1)+(nums.size()-max(mini,maxi));
        int temp=min(back,both);
        return min(front,temp);
    }
};