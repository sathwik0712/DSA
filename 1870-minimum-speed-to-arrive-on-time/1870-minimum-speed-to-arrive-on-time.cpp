class Solution {
public:
    double fn(vector<int>&dist,int h){
        double total=0;
        for(int i=0;i<dist.size()-1;i++){
            total+=ceil((double)dist[i] / h);
        }
        total+=(double)dist.back() / h;
        return total;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1,high=1e7;
        while(low<=high){
            int mid=(low+high)/2;
            double totalH=fn(dist,mid);
            if(totalH<=hour){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        if ( low>1e7)
            return -1;
        return low;
    }
};