class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize=matrix.size();
        int colSize=matrix[0].size();
        //we will imagine the matrix as a 1-d array and calculate the indexes by row=mid/rowSize, col=mid%rowSize
        int low=0, high= (rowSize*colSize)-1;
        
        while(low<=high){
            int mid=(low + (high-low)/2);
            int ele=matrix[mid/colSize][mid%colSize];
            if(ele<target) low=mid+1;
            else if(ele>target) high=mid-1;
            else
                return true;
        }
        return false;
    }
};