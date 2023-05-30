class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        
        int j=0,n=intervals.size();
        for(int ind=1;ind<n;ind++){
            if(intervals[ind][0]<=ans[j][1]){
                ans[j][1]=max(intervals[ind][1],ans[j][1]);
            }
            else{
                ans.push_back(intervals[ind]);
                j++;
            }
        }
        return ans;
    }
};