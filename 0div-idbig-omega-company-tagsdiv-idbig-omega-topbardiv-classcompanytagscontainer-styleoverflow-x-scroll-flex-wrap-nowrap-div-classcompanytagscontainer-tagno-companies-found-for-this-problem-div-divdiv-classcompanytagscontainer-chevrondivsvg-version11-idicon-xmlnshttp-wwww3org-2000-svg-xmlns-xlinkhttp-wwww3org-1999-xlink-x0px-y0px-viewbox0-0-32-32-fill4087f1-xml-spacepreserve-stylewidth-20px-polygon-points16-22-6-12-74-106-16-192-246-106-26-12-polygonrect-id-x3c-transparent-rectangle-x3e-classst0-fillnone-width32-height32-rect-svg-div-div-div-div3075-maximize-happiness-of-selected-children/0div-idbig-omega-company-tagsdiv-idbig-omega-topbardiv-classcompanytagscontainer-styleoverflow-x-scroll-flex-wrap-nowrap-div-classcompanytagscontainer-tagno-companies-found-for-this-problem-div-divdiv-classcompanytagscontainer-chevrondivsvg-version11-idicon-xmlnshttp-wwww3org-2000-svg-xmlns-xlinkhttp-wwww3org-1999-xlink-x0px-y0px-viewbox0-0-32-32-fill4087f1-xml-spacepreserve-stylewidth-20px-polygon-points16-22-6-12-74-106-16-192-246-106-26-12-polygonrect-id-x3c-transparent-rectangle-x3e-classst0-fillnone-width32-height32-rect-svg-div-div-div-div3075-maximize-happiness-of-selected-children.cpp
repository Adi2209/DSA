class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;
        priority_queue<int> pq;
        for(auto it:happiness) pq.push(it);
        int iterations = 0;
        while(k){
            int kid = pq.top();
            pq.pop();
            if(kid-iterations <0) break;
            sum+=kid-iterations;
            iterations++;
            k--;
        }
        return sum;
    }
};