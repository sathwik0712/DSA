class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            int low=0,high=m-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(matrix[i][mid]==target)
                    return true;
                else if(matrix[i][mid]<target)
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return false;
    }
};