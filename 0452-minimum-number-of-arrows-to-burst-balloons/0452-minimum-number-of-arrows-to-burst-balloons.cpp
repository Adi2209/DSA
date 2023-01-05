class Solution {
private:
    static bool cmp(vector<int>& arr1,vector<int>& arr2){
        return arr1[1]<arr2[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),cmp);
        int arrows=1;
        int lastLoc=points[0][1];
        for(int ind=1;ind<n;ind++){
            if(points[ind][0]>lastLoc){
                arrows++;
                lastLoc=points[ind][1];
            }
        }
        return arrows;
    }
};