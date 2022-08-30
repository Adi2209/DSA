class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        //step1 : taking the transpose of the matrix
        
        for(int i=0;i<row;i++){
            for(int j=i;j<col;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
