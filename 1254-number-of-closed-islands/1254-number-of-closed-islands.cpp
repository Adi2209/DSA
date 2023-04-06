class Solution {
private:
    void dfs(vector<vector<int>>& grid,int i,int j){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j])
            return;
        grid[i][j] = 1;
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        for(int i=0;i<r;i++){
            dfs(grid,i,0);
            dfs(grid,i,c-1);
        }
        for(int i=1;i<c-1;i++){
            dfs(grid,0,i);
            dfs(grid,r-1,i);
        }
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};