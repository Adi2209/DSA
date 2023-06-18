class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq;
        for(int ind=0;ind<n;ind++){
            pq.push(nums[ind]);
        }
        int ans=0;
        while(k-- && !pq.empty()){
            ans=pq.top();
            pq.pop();
        }
        return ans;
    }
};