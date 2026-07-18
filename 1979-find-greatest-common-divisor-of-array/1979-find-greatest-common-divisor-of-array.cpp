class Solution {
public:
    int findGCD(vector<int>& nums) {
        int largest=nums[0],smallest=nums[0];
        for (int i=0;i<nums.size();i++){
            if (nums[i]>largest)
                largest=nums[i];
            if (nums[i]<smallest)
                smallest=nums[i];
            
        }
        int gcd=1;
        for(int i=1;i<=smallest;i++){
            if (smallest%i==0 && largest%i==0){
                gcd =i;
            }
        }
        return gcd;
    }
};