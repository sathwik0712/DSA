class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int top=0,bottom=n-1,left=0,right=n-1;
        int curr=1;
        while(curr<=n*n){
            for(int i=left;i<=right;i++)
                ans[top][i]=curr++;
            top++;
            for(int i=top;i<=bottom;i++)
                ans[i][right]=curr++;
            right--;
            for(int i=right; i>=left;i--)
                ans[bottom][i]=curr++;
            bottom--;
            for(int i=bottom; i>=top;i--)
                ans[i][left]=curr++;
            left++;
        }
        return ans;
    }
};