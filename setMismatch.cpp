class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    
        int n = nums.size();
        bool seen[n + 1];
        vector<int> res(2);
        for (int i = 1; i <= n; i++) seen[i] = false;
        for (int& i: nums) seen[i] = (!seen[i] || bool(1 + (res[0] = i)));
        for (int i = 1; i <= n; i++) if (!seen[i]) return res[1] = i, res;
        return res;
    }
};
