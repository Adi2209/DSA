class Solution {
private:
    bool isValid(vector<vector<char>>& board,int row,int col, char ch){
        
        for(int ind=0;ind<9;ind++){
            if(board[row][ind]==ch) return false;
            if(board[ind][col]==ch) return false;
            
            if(board[3*(row/3)+ind/3][3*(col/3)+ind%3]==ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int rowSize=board.size();
        int colSize=board[0].size();
        
        for(int row=0;row<rowSize;row++){
            for(int col=0;col<colSize;col++){
                if(board[row][col]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isValid(board,row,col,ch)){
                            board[row][col]=ch;
                            
                            if(solve(board)) return true;
                            else board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};