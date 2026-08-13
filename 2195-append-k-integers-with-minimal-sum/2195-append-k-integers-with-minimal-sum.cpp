class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int dup=-1;
        long long ans=1LL*k*(k+1)/2;
        for(int i=0;i<n;i++){
            if(nums[i]==dup)
                continue;
            dup=nums[i];
            if(nums[i]<=k){
                ans-=nums[i];
                k++;
                ans+=k;
            }
        }
        return ans;
    }
};