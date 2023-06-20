class Solution {
private:
    bool isValid(int row,int col,vector<string>& board, int n){
        int dupRow=row;
        int dupCol=col;
        
        //checking for upper left diagonal
        while(dupRow>=0 && dupCol>=0){
            if(board[dupRow][dupCol]=='Q') return false;
            dupRow--;
            dupCol--;
        }
        dupRow=row;
        dupCol=col;
        //checking for lower left diagonal
        while(dupRow<n && dupCol>=0){
            if(board[dupRow][dupCol]=='Q') return false;
            dupRow++;
            dupCol--;
        }
        dupRow=row;
        dupCol=col;
        //checking for left col
        while(dupCol>=0){
            if(board[dupRow][dupCol]=='Q') return false;
            dupCol--;
        }
        
        return true;        
    }
    void solve(int col,vector<string>& board,vector<vector<string>>& ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isValid(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
public:
    //brute force solution
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(0,board,ans,n);
        return ans;
    }
};