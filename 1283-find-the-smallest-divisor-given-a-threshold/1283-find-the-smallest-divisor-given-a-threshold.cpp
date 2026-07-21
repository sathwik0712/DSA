
class Solution {
public:
    long long fn(vector<int>&nums,int n){
        long long total=0;
        for(int i=0;i<nums.size();i++){
            total+=(nums[i] + n - 1) / n;
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            long long totalH=fn(nums,mid);
            if(totalH<=threshold){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};