class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mp;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push(mat[i][j]);
            }
        }
        //now all the elements will already be sorted 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // replacing with new values
                mat[i][j]=mp[i-j].top();
                mp[i-j].pop();
            }
        }
        return mat;
    }
};
