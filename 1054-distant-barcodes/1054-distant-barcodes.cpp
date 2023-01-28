class Solution {
private:
    priority_queue<pair<int,int>> getQueue(vector<int>& barcodes){
        unordered_map<int,int> mp;
        for(auto it:barcodes) mp[it]++;
        priority_queue<pair<int,int>> pq;
        for(auto it:mp)
            pq.push({it.second,it.first});
        return pq;
    }
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size()==1 || barcodes.size()==0) return barcodes;
        priority_queue<pair<int,int>> pq=getQueue(barcodes);
        vector<int> ans;
        while(pq.top().first>0){
            auto pair1=pq.top();
            pq.pop();
            ans.push_back(pair1.second);
            pair1.first--;
            auto pair2=pq.top();
            pq.pop();
            if(pair2.first>0){
                ans.push_back(pair2.second);
                pair2.first--;
            }
            pq.push(pair1);
            pq.push(pair2);
        }
        return ans;
    }
};