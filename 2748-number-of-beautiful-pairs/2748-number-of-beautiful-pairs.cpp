class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                string s1=to_string(nums[i]);
                string s2=to_string(nums[j]);
                int n1 = s1[0] - '0'; 
                int n2 = s2.back() - '0';
                
                if (__gcd(n1,n2) == 1)res++;
            }
        }
        return res;
    }
};