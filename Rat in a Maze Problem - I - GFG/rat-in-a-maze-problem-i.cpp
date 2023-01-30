//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool isValid(int nRow,int nCol,int n,vector<vector<int>>& vis,vector<vector<int>>& m){
        return nRow>=0 && nRow<n && nCol>=0 && nCol<n &&
        !vis[nRow][nCol] && m[nRow][nCol]==1;
    }
    void reachDest(int row,int col,vector<vector<int>>& m,int n,vector<vector<int>>& vis,
    vector<string>& ans,string moves){
        
        if(row==n-1 && col==n-1){
            ans.push_back(moves);
            // moves="";
            return;
        }
        
        vector<int> delRow{1,0,0,-1};
        vector<int> delCol{0,-1,1,0};
        string possibleMove="DLRU";
        for(int ind=0;ind<4;ind++){
            int nRow=row+delRow[ind];
            int nCol=col+delCol[ind];
            if(isValid(nRow,nCol,n,vis,m)){
                vis[row][col]=1;
                reachDest(nRow,nCol,m,n,vis,ans,moves+possibleMove[ind]);
                vis[row][col]=0;
            }
        }
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0]==1)
            reachDest(0,0,m,n,vis,ans,"");
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends