//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    public:
    vector<int> rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findUPar(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUPar(parent[node]);
    }
    
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=parent[ulp_v];
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    
};
class Solution {
  private:
    bool isValid(int adjr,int adjc, int n, int m){
        return adjr>=0 && adjr<n && adjc>=0 && adjc<m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        vector<int> ans;
        
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            vector<int> delRow{-1,0,1,0};
            vector<int> delCol{0,1,0,-1};
            for(int ind=0;ind<4;ind++){
                int adjR=row+delRow[ind];
                int adjC=col+delCol[ind];
                if(isValid(adjR,adjC,n,m)){
                    if(vis[adjR][adjC]){
                       int nodeNo=row*m+col;
                       int adjNodeNo=adjR*m+adjC;
                       if(ds.findUPar(nodeNo)!=ds.findUPar(adjNodeNo)){
                           cnt--;
                           ds.unionBySize(nodeNo,adjNodeNo);
                       }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends