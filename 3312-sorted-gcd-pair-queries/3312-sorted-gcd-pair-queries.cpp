class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        int maxVal=*max_element(begin(nums),end(nums));
        vector<int>divisorFreq(maxVal+1,0);
        for(int i=0;i<n;i++){
            int num=nums[i];
            for(int j=1;j*j<=num;j++){
                if(num%j==0){
                    divisorFreq[j]++;
                    if(num/j!=j)
                        divisorFreq[num/j]++;
                }
            }
        }
        vector<long long>pairswithgcd(maxVal+1,0);
        for(int g=maxVal;g>=1;g--){
            long long count =divisorFreq[g];
            pairswithgcd[g]=count*(count-1)/2;
            for(int mult=2*g;mult<=maxVal;mult+=g){
                pairswithgcd[g]-=pairswithgcd[mult];
            }
        }
        vector<long long>prefixcountgcd(maxVal+1,0);
        for(int g=1;g<=maxVal;g++)
            prefixcountgcd[g]=prefixcountgcd[g-1]+pairswithgcd[g];
        vector<int>result;
        for(long long idx:queries){
            int l=1,r=maxVal,temp=1;
            while(l<=r){
                int midgcd=l+(r-l)/2;
                if(prefixcountgcd[midgcd]>idx){
                    temp=midgcd;
                    r=midgcd-1;
                }else
                    l=midgcd+1;
            }
            result.push_back(temp);
        }
        return result;
    }
};