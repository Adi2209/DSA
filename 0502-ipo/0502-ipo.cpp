class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> pq;
        vector<pair<int,int>> projects; 
        for(int i = 0;i<Capital.size();i++){
            projects.push_back({Capital[i],i});
        }
        sort(projects.begin(),projects.end());
        int ans = W;
        int j = 0;
        while(k){
            //push values
            while(j<Capital.size() && projects[j].first<=W){
                pq.push(Profits[projects[j].second]);// push all profits for which capital<=W
                j++;
            }
            if(!pq.empty()){
                ans+=pq.top();// take the max profit among them
                W = W+pq.top();// new capital
                pq.pop();
               
            }
             k--;
            
        }
        return ans;
        
    }
};