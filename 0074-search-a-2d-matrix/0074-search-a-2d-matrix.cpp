class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize=matrix.size();
        int colSize=matrix[0].size();
        //we will imagine the matrix as a 1-d array and calculate the indexes by row=mid/colSize, col=mid%colSize
        
        int low=0,high=(rowSize*colSize)-1;
        
        while(low<=high){
            //to avoid overflow
            int mid=(low+(high-low)/2);
            int nRow=mid/colSize, nCol=mid%colSize;
            int element=matrix[nRow][nCol];
            if(element<target) low=mid+1;
            else if(element>target) high=mid-1;
            else return true;
        }
        return false;
    }
};