class Solution {
private:
bool isValid(int row, int col, int rowSize, int colSize, vector<vector<int>>& grid) {
        return row < rowSize && row >= 0 && col < colSize && col >= 0;
    }

    void dfs(int row, int col, int rowSize, int colSize, int& gold, int& maxGold, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        vector<int> delRow{-1, 0, 1, 0};
        vector<int> delCol{0, 1, 0, -1};
        for (int ind = 0; ind < 4; ind++) {
            int nRow = row + delRow[ind];
            int nCol = col + delCol[ind];
            if (isValid(nRow, nCol, rowSize, colSize, grid) && vis[nRow][nCol]!= 1 && grid[row][col]!= 0) {
                gold += grid[nRow][nCol];
                maxGold = max(maxGold, gold);
                dfs(nRow, nCol, rowSize, colSize, gold, maxGold, grid, vis);
                // Backtrack
                gold -= grid[nRow][nCol];
            }
        }
        // Reset visited status after exploring all paths from this cell
        vis[row][col] = 0;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        vector<vector<int>> vis(rowSize, vector<int>(colSize, 0));
        int maxGold = 0;
        for (int row = 0; row < rowSize; row++) {
            for (int col = 0; col < colSize; col++) {
                if (grid[row][col] > 0) {
                    int gold = grid[row][col]; // Initialize gold to 0 before starting DFS
                    dfs(row, col, rowSize, colSize, gold, maxGold, grid, vis);
                }
            }
        }
        return maxGold;
    }
};
