class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        unordered_map<char,int> mp; //(key,value)
        priority_queue<pair<int,char> >pq;//value,key because we have to work with value 
        
        for(auto &i:s) mp[i]++;
        
        for(auto &i:mp) pq.push({i.second,i.first});
        
        while(pq.size()>1){
            auto top1=pq.top();pq.pop();
            auto top2=pq.top();pq.pop();
            
            ans+=top1.second;
            ans+=top2.second;
            
            top1.first --;
            top2.first --;
            
            if(top1.first > 0)
                pq.push(top1);
            
            if(top2.first > 0)
                pq.push(top2);
            
            
        }
        if(!pq.empty()){
            if(pq.top().first > 1)
                return "";
            
            else
                ans+=pq.top().second;
        }
        
        return ans;
    }
};