class Solution {
public:
    int findp(int x, vector<int> &par){
    if(par[x]!=x){
        par[x]=findp(par[x],par);
    }
    return par[x];
}
void unio(int x,int y, vector<int> &par){
    int p1=findp(x,par);
    int p2=findp(y,par);
    if(p1!=p2){
        par[p2]=p1;
    }
}


int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    unordered_map<int,vector<int>> gA;
    unordered_map<int,vector<int>> gB;
    unordered_map<int,vector<int>> gC;
    
    for(auto r:edges){
        if(r[0]==1){
            gA[r[1]].push_back(r[2]);
            gA[r[2]].push_back(r[1]);
        }else if(r[0]==2){
            gB[r[1]].push_back(r[2]);
            gB[r[2]].push_back(r[1]);
        }else{
            gC[r[1]].push_back(r[2]);
            gC[r[2]].push_back(r[1]);
        }
    }
    vector<int> par;
    par.resize(n+1,0);
    for(int i=1;i<=n;i++){
        par[i]=i;
    }
    
    int ed=0;
    int cnt=0;
    
    
    
    for(int i=1;i<=n;i++){
        for(int j:gC[i]){
            int p1=findp(i,par);
            int p2=findp(j,par);
            if(p1==p2){
                continue;
            }else{
                unio(i,j,par);
                ed++;
            }
        }
    }
   
    vector<int> pa=par;
    vector<int> pb=par;
    int ed1=ed;
    int ed2=ed;
    for(int i=1;i<=n;i++){
        int p1=findp(i,pa);
       
        for(auto j:gA[i]){
            int p2=findp(j,pa);
            if(p1==p2){
                continue;
            }else{
                unio(i,j,pa);
                ed1++;
            }
        }
        int p4=findp(i,pb);
         for(auto k:gB[i]){
            int p3=findp(k,pb);
            if(p4==p3){
                continue;
            }else{
                unio(i,k,pb);
                ed2++;
            }
        }
    }
 
    
    if(ed1!=n-1 || ed2!=n-1 ){
        return -1;
    }
    return edges.size()-(ed1+ed2-ed);
   
}
};