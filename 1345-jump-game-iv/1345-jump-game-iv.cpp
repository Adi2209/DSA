class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=size(arr);
        if(n==1) return 0;   //  edge case : )
        unordered_map<int,list<int>>mp;    // ele -> all its same guys 
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);
        queue<int>q;
        vector<bool>vis(n,false);
        q.push(0); vis[0]=true;
        int step=0;
        while(!q.empty()){
            
            int sz=size(q);
            while(sz--){
                int fr=q.front(); q.pop();
                if(fr==n-1) return step; // if u reached the last ind then return count step;
                // else now vist all its neighs who are i+1,i-1 and same guys 
                list<int>& neigh=mp[arr[fr]];
                neigh.push_back(fr-1); 
                neigh.push_back(fr+1);
                // since the left and right guys of ith ele are not there in its list
				
                // so now iterate through neigh who are within the range and not vis
                for(auto x: neigh){
                    if(x>=0 and x<n and !vis[x]){q.push(x); vis[x]=true;}
                }
                neigh.clear();  // removing the visited ones to reduce the reptiive work;
                // as the children are already visted and no use for the coming iterations for 
                // any further guy in coming iterations; bcz we have already used that path and didnt got the ans ,so not allowing to use this path;
            }
            step++; // counting the steps
        }
        return 0;
    }
};