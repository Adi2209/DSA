class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<string> pq;
        
        for(int i=0;i<words.size();i++){
            pq.push(words[i]);
        }
        vector<string> ans;
        while(k!=0){
            string ele=pq.top();
            pq.pop();
            if(k==0)
                ans.push_back(ele);
            k--;
        }
        return ans;
    }
};
