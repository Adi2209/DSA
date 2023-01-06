class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int icecreamCnt=0;
        sort(costs.begin(),costs.end());
        
        for(auto &cost:costs){
            if(cost<=coins){
                icecreamCnt++;
                coins-=cost;
            }
        }
        return icecreamCnt;
    }
};