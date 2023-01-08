class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto &it:nums) pq.push(it);
        
        long long finalScore=0;
        for(int i=0;i<k;i++){
            int res=pq.top();
            pq.pop();
            finalScore+=res;
            int ceilValue=ceil(res/3.00);
            pq.push(ceilValue);
        }
        return finalScore;
    }
};