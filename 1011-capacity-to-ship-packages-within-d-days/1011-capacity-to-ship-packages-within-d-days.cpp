class Solution {
public:
    int possible(vector<int>& weights,int mid){
        int count=1,sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>mid){
                count++;
                sum=weights[i];
            }else {
                sum+=weights[i];
            }
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=0;
        for(int i=0;i<weights.size();i++){
            maxi+=weights[i];
        }
        int low=*max_element(begin(weights),end(weights)),high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            int requiredDays=possible(weights,mid);
            if(requiredDays<=days)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};