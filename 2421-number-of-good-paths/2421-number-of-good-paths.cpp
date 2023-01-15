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
        int up=findUPar(u);
        int uv=findUPar(v);
        if(up==uv) return ;
        if(up < uv) {
            parent[uv] = up; 
        }
        else {
            parent[up] = uv;
        }
    }
    
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adjacency(n);
        map<int, vector<int>> value2nodes;
        for (int i = 0; i < n; ++i) {
            value2nodes[vals[i]].push_back(i);
        }
        for (auto& edge : edges) {
            int nodeA = edge[0];
            int nodeB = edge[1];
            // store node with large value -> node with val small value
            // so that we can connect two nodes only when the larger node is considered
            if (vals[nodeA] >= vals[nodeB]) {
                adjacency[nodeA].push_back(nodeB);
            }
            if (vals[nodeA] <= vals[nodeB]) {
                adjacency[nodeB].push_back(nodeA);
            }
        }
        DisjointSet disjointSet(n);
        
        int res = 0;
        // from the nodes with small value
        for (auto& element : value2nodes) {
            int value = element.first;
            // connect the corresponding neighbors
            for (auto& node : element.second) {
                for (auto& neighbor : adjacency[node]) {
                    disjointSet.unionBySize(node, neighbor);
                }
            }
            // check how many groups are there 
            // and how many nodes with current value are there in each group
            unordered_map<int, int> group2size;
            for (auto& node : element.second) {
                group2size[disjointSet.findUPar(node)]++;
            }
            // case 1: node to itself
            res += element.second.size();
            
            // case 2: in each group, if there are >= two nodes with the current value, count how many pairs will be formed
            for (auto& [groupID, size] : group2size) {
                if (size > 1) {
                    res += (size * (size - 1)) / 2;
                }
            }
        }
        return res;
    }
};