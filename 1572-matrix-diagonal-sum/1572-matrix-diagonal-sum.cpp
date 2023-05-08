class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, n = mat.size();
        for (int i = 0; i < n; i++) {
            sum += mat[i][i] + mat[i][n - 1 - i];
        }
        if (n % 2 == 1) {
            return sum - mat[n / 2][n / 2];
        }
        return sum;      
    }
};