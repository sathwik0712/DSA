class Solution {
public:
    long long  totaltrips(vector<int>&time, long long mid){
        long long  sum=0;
        for(int i=0;i<time.size();i++){
            sum+=mid/time[i];
        }
        return sum;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long mini=*min_element(time.begin(),time.end());
        long long low=1;
        long long high=mini*totalTrips;
        while(low<=high){
            long long  mid=low+(high-low)/2;
            long long  total=totaltrips(time,mid);
            if(total>=totalTrips)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};