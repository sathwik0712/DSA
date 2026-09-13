class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res; 
        sort(nums.begin(),nums.end());
        do{
            vector<int>temp;
            for(int n: nums)
                temp.push_back(n);
            res.push_back(temp);
        }while(next_permutation(nums.begin(),nums.end()));
        return res;
    }
};