class Solution {
private:
void dfs(int node,vector<int>& vis,vector<vector<int>> adjList){
vis[node]=1;
for(auto it: adjList[node]){
if(!vis[it])
dfs(it,vis,adjList);
}
}
public:
int findCircleNum(vector<vector<int>>& isConnected) {
//first we will make the adjList from the adjMatrix
int n=isConnected.size();
vector<vector<int>> adjList(n);
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(isConnected[i][j]==1 && i!=j){
adjList[i].push_back(j);
adjList[j].push_back(i);
}
}
}
//now traversing the dfs
int cnt=0;
vector<int> vis(n,0);
for(int i=0;i<n;i++){
if(!vis[i]){
cnt++;
dfs(i,vis,adjList);
}
}
return cnt;
}
};