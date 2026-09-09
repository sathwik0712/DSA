class Solution {
public:
    long long countCommas(long long n) {
        long long res=0,p=1000;
        while(p<=n){
            long long r=n%1000;
            res=res+n-p+1;
            p*=1000;
        }
        return res;
    }
};