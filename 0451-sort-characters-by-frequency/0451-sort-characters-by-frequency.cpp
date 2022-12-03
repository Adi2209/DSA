class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> freq;
        
        priority_queue<pair<int,char> >q;//maxheap
        
        for(auto i:s) freq[i]++;
        
        for(auto[j,frq]:freq) q.push({frq,j});
        
        string ans="";
        
        pair<int,char> curr;
        
        while(!q.empty()){
            curr=q.top();
            q.pop();
            ans+=string(curr.first,curr.second);
        }
        return ans;
    }
};