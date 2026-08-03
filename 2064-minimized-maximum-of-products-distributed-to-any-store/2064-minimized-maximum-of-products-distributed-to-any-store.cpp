class Solution {
public:
    long long fn(int n,vector<int>&quantities){
        long long total=0;
        for(int i=0;i<quantities.size();i++){
            total+=ceil((double)quantities[i]/n);
        }
        return total;
    }
    int minimizedMaximum(int n,vector<int>& quantities) {
        int low=1,high=*max_element(quantities.begin(),quantities.end());
        while(low<=high){
            int mid=(low+high)/2;
            long long totalH=fn(mid,quantities);
            if(totalH<=n){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};