class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans,visited(n);
        
        for(auto &edge:edges){
            visited[edge[1]]=1;
        }
        for(int ind=0;ind<n;ind++){
            if(visited[ind]==0) ans.push_back(ind);
        }
        return ans;
    }
};