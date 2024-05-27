class Solution {
public:
    int check(vector<int>& n, int idx) {
        int count = 0;
        for(int i = 0; i < n.size(); i++) {
            if(idx <= n[i]) {
                count++;
            }
        }

        return count;
    }
    int specialArray(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i <= nums.size(); i++) {
            if(check(nums, i) == i) {
                return i;
            }
        }

        return -1;
    }
};