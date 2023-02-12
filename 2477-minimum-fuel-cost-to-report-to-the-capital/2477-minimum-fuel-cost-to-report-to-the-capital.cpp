class Solution {
private:
    int solveDFS(int node,int prev,vector<vector<int>>& adjList,int seats,long long& fuel){
        int persons=1;
        for(auto it:adjList[node]){
            if(it==prev) continue;
            persons+=solveDFS(it,node,adjList,seats,fuel);
        }
        if(node!=0){
            fuel+=(persons+seats-1)/seats;
        }
        return persons;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<vector<int>> adjList(n+1);
        vector<int> vis(n,0);
        for(auto it:roads){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        long long fuel=0;
        solveDFS(0,-1,adjList,seats,fuel);
        return fuel;
    }
};