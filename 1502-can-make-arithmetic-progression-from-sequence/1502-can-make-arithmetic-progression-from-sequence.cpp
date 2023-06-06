class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
        if(n<2) return false;
        sort(arr.begin(),arr.end());
        int commonDiff=abs(arr[0]-arr[1]);
        for(int ind=1;ind<n;ind++){
            int diff=abs(arr[ind-1]-arr[ind]);
            if(diff!=commonDiff) return false;
        }
        return true;
    }
};