class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums){
        long long ans=0;
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            string temp =to_string(nums[low]) + to_string(nums[high]);
            ans += stoi(temp);   
            low++;
            high--;
        }
        if(low==high){
           string res=to_string(nums[low]);
           ans+=stoi(res);
        }
        return ans; 
    }
};