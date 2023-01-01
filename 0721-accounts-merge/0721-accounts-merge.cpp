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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //Step 1: connecting the nodes making the disjoint set and making the ultimate parent
        int n=accounts.size();
        unordered_map<string,int> mapMailNode;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end()){
                    mapMailNode[mail]=i;
                }
                else{
                    ds.unionBySize(i,mapMailNode[mail]);
                }
            }
        }
        //Step 2: merging the mails according to the disjoint set 
        vector<string> mergedMail[n];
        for(auto it: mapMailNode){
            string mail=it.first;
            int node=ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }
        //Step 3: sorting the merged list and rearranging according to the parent
        vector<vector<string>> ans;
        
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0){
                continue;
            }
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};