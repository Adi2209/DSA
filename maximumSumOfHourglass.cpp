class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int maxi=INT_MIN;
        int r=grid.size();
        int c=grid[0].size();
        int sum=0;
        for(int i=0;i<=r-3;i++){
            for(int j=0;j<=c-3;j++){
                sum=0;
                for(int k=j;k<j+3;k++){
                    sum+=grid[i][k];
                    sum+=grid[i+2][k];
                }
                sum+=grid[i+1][j+1];
                maxi=max(sum,maxi);
            }
        }
        return maxi;
    }
};
