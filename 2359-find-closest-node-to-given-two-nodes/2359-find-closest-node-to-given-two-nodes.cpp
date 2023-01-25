class Solution {
private:
    void storePath(int ind,int distance,vector<int>& edges,vector<int>& path){
        
        if(ind!=-1 && path[ind]==-1){
            //solving one case
            path[ind]=distance;
            //recursive call for next cases
            storePath(edges[ind],distance+1,edges,path);
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n=edges.size();
        vector<int> path1(n,-1),path2(n,-1);
        int ans=-1,minDistance=INT_MAX;
        
        storePath(node1,0,edges,path1);
        storePath(node2,0,edges,path2);
        
        for(int ind=0;ind<n;ind++){
            if(min(path1[ind],path2[ind])>=0 && max(path1[ind],path2[ind])<minDistance){
                minDistance=max(path1[ind],path2[ind]);
                ans=ind;
            }
        }
        return ans;
    }
};