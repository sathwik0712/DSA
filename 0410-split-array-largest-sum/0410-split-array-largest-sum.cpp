class Solution {
public:
    bool possible(int barrier,vector<int>&nums,int k){
        int allocated=1;
        long long ele=0;
        for(int i=0;i<nums.size();i++){
            if(barrier<nums[i])
                return false;
            if(ele+nums[i]>barrier){
                ele=nums[i];
                allocated++;
            }else{
                ele+=nums[i];
            }
        }
        if(allocated>k)
            return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        if (k>nums.size())
            return -1;
        int low=*max_element(begin(nums),end(nums));
        long long  high=accumulate(begin(nums),end(nums),0LL);
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(mid,nums,k)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};