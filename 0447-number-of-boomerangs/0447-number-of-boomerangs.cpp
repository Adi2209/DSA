class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int boomerangs=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            for(int j=0;j<n;j++){
                int dist=pow(points[j][1]-points[i][1],2)+pow(points[j][0]-points[i][0],2);
                if(mp[dist]>0){
                    boomerangs+= mp[dist]*2;
                }
                mp[dist]++;
            }
        }
        return boomerangs;
    }
};