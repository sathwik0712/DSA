 class Solution {
public:
    int gcd(int a,int b){
        while(a>0 && b>0){
            if(a>b)
                a=a%b;
            else
                b=b%a;
        }
        if(a==0)
            return b;
        else
            return a;
    }
    long long gcdSum(vector<int>& nums) {
        vector<int>prefixGcd(nums.size());
        vector<int>mx(nums.size());
        mx[0]=nums[0];
        prefixGcd[0]=gcd(nums[0],nums[0]);
        for(int i=1;i<nums.size();i++){
            mx[i]=max(mx[i-1],nums[i]);
            prefixGcd[i]=gcd(nums[i],mx[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        if(prefixGcd.size()%2==1){
            int mid=prefixGcd.size()/2;
            prefixGcd.erase(prefixGcd.begin()+mid);
        }
        int low=0,high=prefixGcd.size()-1;
        long long sum=0;
        while(low<=high){
            sum=sum+gcd(prefixGcd[low],prefixGcd[high]);
            low++;
            high--;
        }
        return sum;
    }
};