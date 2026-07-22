class Solution {
public:
    bool possible(vector<int>& bloomDay,int mid,int m,int k){
        int count=0,nbloom=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(mid>=bloomDay[i])
                count++;
            else{
                nbloom+=count/k;
                count=0;
            }
        }
        nbloom+=count/k;
        if(nbloom>=m)
            return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n=bloomDay.size();
        if(1LL*m*k>n)
            return -1;
        int low=*min_element(begin(bloomDay),end(bloomDay));
        int high=*max_element(begin(bloomDay),end(bloomDay));
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k))
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};