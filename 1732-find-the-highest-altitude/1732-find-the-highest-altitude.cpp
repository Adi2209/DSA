class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // support variables
        int res = 0, curr = 0;
        for (int n: gain) {
            // updating curr
            curr += n;
            // updating res
            res = max(res, curr);
        }
        return res;
    }
};