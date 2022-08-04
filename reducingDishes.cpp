class Solution {
private:
    int solveSO(vector<int>& satisfaction,int idx,int time){
        int n=satisfaction.size();
        
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        
        for(int idx=n-1;idx>=0;idx--){
            for(int time=idx;time>=0;time--){
                int include=satisfaction[idx]*(time+1)+ next[time+1];
                int exclude=0+next[time];
        
                curr[time]=max(exclude,include);
            }
            next=curr;
        }
        return next[0];
        
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        
        return solveSO(satisfaction,0,0);
        
    }
};
