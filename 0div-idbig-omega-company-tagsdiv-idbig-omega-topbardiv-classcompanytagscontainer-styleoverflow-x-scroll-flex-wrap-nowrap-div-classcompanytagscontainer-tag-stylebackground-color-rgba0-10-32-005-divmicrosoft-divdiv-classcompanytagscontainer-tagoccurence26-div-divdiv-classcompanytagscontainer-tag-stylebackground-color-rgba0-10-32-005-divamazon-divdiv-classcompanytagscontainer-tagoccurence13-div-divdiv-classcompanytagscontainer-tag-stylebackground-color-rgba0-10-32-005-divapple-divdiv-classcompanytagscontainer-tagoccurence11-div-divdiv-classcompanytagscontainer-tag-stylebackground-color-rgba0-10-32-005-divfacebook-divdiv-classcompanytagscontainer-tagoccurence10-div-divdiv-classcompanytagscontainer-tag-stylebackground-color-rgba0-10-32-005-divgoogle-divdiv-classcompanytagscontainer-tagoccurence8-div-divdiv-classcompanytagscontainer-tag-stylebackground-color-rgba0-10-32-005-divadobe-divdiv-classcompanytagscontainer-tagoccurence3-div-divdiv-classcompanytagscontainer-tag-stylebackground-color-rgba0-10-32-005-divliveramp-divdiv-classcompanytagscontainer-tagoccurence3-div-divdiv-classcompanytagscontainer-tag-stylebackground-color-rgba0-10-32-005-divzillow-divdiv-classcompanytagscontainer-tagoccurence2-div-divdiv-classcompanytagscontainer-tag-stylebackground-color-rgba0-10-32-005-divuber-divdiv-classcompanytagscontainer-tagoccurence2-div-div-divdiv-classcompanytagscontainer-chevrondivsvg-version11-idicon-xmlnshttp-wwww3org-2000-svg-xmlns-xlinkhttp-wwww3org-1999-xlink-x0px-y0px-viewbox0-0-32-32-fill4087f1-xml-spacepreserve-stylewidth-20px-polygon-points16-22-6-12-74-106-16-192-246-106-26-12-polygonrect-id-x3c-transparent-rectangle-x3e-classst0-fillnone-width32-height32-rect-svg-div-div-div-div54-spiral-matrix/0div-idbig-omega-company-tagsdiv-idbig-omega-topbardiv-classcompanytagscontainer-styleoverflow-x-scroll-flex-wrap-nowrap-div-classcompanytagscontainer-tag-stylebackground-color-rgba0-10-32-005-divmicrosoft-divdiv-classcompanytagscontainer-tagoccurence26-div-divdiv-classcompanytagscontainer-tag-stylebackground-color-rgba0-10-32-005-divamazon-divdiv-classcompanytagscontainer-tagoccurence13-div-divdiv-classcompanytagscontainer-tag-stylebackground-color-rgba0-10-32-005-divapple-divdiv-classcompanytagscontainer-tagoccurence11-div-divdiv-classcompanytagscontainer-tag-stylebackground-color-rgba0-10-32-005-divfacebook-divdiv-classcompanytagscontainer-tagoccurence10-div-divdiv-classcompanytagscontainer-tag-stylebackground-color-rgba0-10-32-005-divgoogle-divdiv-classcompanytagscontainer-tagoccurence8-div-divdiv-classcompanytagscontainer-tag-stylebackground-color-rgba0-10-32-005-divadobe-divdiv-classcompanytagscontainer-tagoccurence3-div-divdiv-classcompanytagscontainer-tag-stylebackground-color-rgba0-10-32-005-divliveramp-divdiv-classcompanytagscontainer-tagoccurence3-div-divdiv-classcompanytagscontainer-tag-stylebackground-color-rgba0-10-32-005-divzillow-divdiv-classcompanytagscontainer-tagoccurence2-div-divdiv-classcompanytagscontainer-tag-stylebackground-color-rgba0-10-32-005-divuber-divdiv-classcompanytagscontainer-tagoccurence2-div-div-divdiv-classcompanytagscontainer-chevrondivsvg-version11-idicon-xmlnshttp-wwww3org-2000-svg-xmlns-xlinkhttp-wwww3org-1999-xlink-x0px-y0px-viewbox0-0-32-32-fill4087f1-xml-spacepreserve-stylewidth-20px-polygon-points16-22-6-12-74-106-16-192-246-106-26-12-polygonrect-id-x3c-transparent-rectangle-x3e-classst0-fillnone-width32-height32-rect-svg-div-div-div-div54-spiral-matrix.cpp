class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowSize= matrix.size(), colSize = matrix[0].size();
        int top = 0, left = 0 ,bottom = rowSize-1, right = colSize-1;
        int direction = 1;
        vector<int> ans;
        while(left<=right && top<=bottom){
            if(direction == 1){
                for(int ind=left;ind<=right;ind++) ans.push_back(matrix[top][ind]);
                top++;
                direction = 2;
            }
            else if(direction ==2){
                for(int ind=top;ind<=bottom;ind++) ans.push_back(matrix[ind][right]);
                right--;
                direction = 3;
            }
            else if(direction ==3){
                for(int ind=right;ind>=left;ind--) ans.push_back(matrix[bottom][ind]);
                bottom--;
                direction = 4;
            }
            else if(direction == 4){
                for(int ind=bottom;ind>=top;ind--) ans.push_back(matrix[ind][left]);
                direction = 1;
                left++;
            }  
        }
        return ans;
    }
};