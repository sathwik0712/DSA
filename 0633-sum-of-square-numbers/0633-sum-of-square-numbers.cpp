class Solution {
public:
    bool judgeSquareSum(int c) {
        long low=0,high=sqrt(c);
        while(low<=high){
            long long sum=low*low+high*high;
            if(sum==c)
                return true;
            else if(sum<c)
                low++;
            else
                high--;
        }
        return false;
    }
};