class Solution {
public:
    int solve(vector<vector<int>>& grid, int i , int j, int n , int m){
        if(i>=n)
            return j;
        
        if(grid[i][j]==1){
            if(j==m-1 || grid[i][j+1]==-1)
                return -1;
           
            if(grid[i][j+1]==1)
                return solve(grid,i+1,j+1,n,m);
        }
        
        if(grid[i][j]==-1){
            if(j==0 || grid[i][j-1]==1)
                return -1;
            
            if(grid[i][j-1]==-1)
                return solve(grid,i+1,j-1,n,m);
        }
        
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> ans;
        
        for(int i=0;i<m;i++){
            int outColumn=solve(grid,0,i,n,m);
            ans.push_back(outColumn);
        }
        
        return ans;
    }
};
