class Solution {
private:
    bool reachDest(int ind ,vector<int>& arr,vector<bool>& vis){
        if(ind>=arr.size()) return false;
        if(arr[ind]==0) return true;
        if(vis[ind]) return false;
        
        vis[ind]=true;
        bool right=reachDest(ind+arr[ind],arr,vis);
        bool left=reachDest(ind-arr[ind],arr,vis);
        return left||right;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(),0);
        return reachDest(start,arr,vis);
    }
};