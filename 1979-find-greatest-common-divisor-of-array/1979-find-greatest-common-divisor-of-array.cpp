class Solution {
public:
    int gcd(int a , int b){
        while(a>0 && b>0){
            if(a>b)
                a=a%b;
            else
                b=b%a;
        }
        if(a==0)
            return b;
        return a;
    }
    int findGCD(vector<int>& nums) {
        int minVal=*min_element(begin(nums),end(nums));
        int maxVal=*max_element(begin(nums),end(nums));
        return gcd(maxVal,minVal);
    }
};