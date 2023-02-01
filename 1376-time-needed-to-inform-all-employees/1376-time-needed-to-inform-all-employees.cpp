class Solution {
private:
    int traverseDFS(int node,vector<int>& manager,vector<int>& informTime,vector<int> adjList[]){
        int time=0;
        
        for(auto it:adjList[node]){
            time=max(time,traverseDFS(it,manager,informTime,adjList));
        }
        time+=informTime[node];
        return time;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adjList[n];
        
        for(int ind=0;ind<n;ind++){
            if(manager[ind]==-1) continue;
            adjList[manager[ind]].push_back(ind);
        }
        return traverseDFS(headID,manager,informTime,adjList);

    }
};