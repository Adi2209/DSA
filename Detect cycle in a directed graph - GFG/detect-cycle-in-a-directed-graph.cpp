//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V);
	    
	    for(int i=0;i<V;i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	   // pushing the first element with indegree 0 , as one will have indegree =0 always
	   //as it is a DAG
	   
	   for(int i=0;i<V;i++){
	       if(indegree[i]==0) q.push(i);
	   }
	   
	   vector<int> topo;
	   
	   while(!q.empty()){
	       int node=q.front();
	       q.pop();
	       topo.push_back(node);
	       for(auto it:adj[node]){
	           indegree[it]--;
	           if(indegree[it]==0) q.push(it);
	       }
	   }
	   return topo.size()==V? false:true;
	   
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends