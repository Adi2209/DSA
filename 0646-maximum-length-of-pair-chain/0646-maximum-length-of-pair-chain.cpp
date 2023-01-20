class Solution {
private:
    static bool cmp(vector<int> &arr1,vector<int>& arr2){
        return arr1[1]<arr2[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int n=pairs.size();
        //cnt will start from 1 as first pair will always be included
        int cnt=1,j=0;
        for(int ind=1;ind<n;ind++){
            int C=pairs[ind][0];
            int B=pairs[j][1];
            if(B<C){
              j=ind;
              cnt++;  
            } 
        }
        return cnt;
    }
};