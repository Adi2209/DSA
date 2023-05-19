class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        int turn=1,ind=1;
        vector<int> mark(n+1,0);
        while(!mark[ind]){
            mark[ind] = 1;
            ind=((ind+turn*k)%n);
            if(ind==0)ind = n;
            turn++;
        }
        vector<int> ans;
        for(turn = 1; turn <= n; turn++){
            if(!mark[turn])ans.push_back(turn);
        }
        return ans;
    }
};