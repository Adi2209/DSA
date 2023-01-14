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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        DisjointSet ds(26);
        for(int i=0;i<n;i++){
            ds.unionBySize(s1[i]-'a',s2[i]-'a');
        }
        string res="";
        for(int i=0;i<baseStr.size();i++){
            res+=(char)(ds.findUPar(baseStr[i]-'a')+'a');
        }
        return res;
    }
};