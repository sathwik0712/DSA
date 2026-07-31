class Solution {
public:
    long long fn(vector<int> &candies,int mid){
        long long total=0;
        for(int i=0;i<candies.size();i++){
            total+=candies[i]/mid;
        }
        return total;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=accumulate(candies.begin(),candies.end(),0LL);
        if ( sum < k)
            return 0;
        int low=1,high=*max_element(begin(candies),end(candies));
        while(low<=high){
            int mid=(low+high)/2;
            long long  total=fn(candies,mid);
            if(total>=k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }
};