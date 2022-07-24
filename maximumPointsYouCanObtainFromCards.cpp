class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n=cardPoints.size();
        int sum=0;
        int ans=0;
        for(int i=0;i<k;i++) sum+=cardPoints[i];
        ans=sum;
        for(int i=0;i<k;i++){
            ans=max(ans,sum+=cardPoints[n-i-1]-cardPoints[k-i-1]);
        }
        return ans;
    }
};