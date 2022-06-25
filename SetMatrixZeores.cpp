class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int col0 = 1, rows = v.size(), cols = v[0].size();

    for (int i = 0; i < rows; i++) {
        if (v[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (v[i][j] == 0)
                v[i][0] = v[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (v[i][0] == 0 || v[0][j] == 0)
                v[i][j] = 0;
        if (col0 == 0) v[i][0] = 0;
        
    }
    }
};