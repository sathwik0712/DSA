class Solution {
public:
    long long fn(vector<int>&nums,int  mid){
        long long total=0;
        for(int i=0;i<nums.size();i++)
            total+=ceil((nums[i]-1)/mid);
        return total;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            long long totalH=fn(nums,mid);
            if(totalH<=maxOperations)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};