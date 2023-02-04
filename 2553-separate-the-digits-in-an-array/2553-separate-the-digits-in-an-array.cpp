class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto it:nums){
            vector<int> res;
            while(it){
                int digit=it%10;
                res.push_back(digit);
                it/=10;
            }
            for(int ind=res.size()-1;ind>=0;ind--) ans.push_back(res[ind]);
            
        }
        return ans;
    }
};