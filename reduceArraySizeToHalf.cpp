class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        int sizeNeeded=n/2;
        
        unordered_map<int,int> mp;
        for(auto i:arr) mp[i]++;
        
        priority_queue<int> pq;
        
        for(auto i:mp) pq.push(i.second);
        int cnt=0,ans=0;
        while(cnt<sizeNeeded){
            cnt+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};
