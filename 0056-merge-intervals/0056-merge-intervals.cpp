class Solution {
private:
    void printans(vector<vector<int>>& ans){
        for(auto it:ans){
            cout<<it[0]<<" , "<<it[1];
            cout<<endl;
        }
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        // printans(ans);
        int j=0,n=intervals.size();
        for(int ind=1;ind<n;ind++){
            if(ans[j][1]>=intervals[ind][0]){
                ans[j][1]=max(intervals[ind][1],ans[j][1]);
            }
            else{
                ans.push_back(intervals[ind]);
                j++;
            }
            // printans(ans);
        }
        return ans;
    }
};