class Solution {
private:
    bool isPossible(int day,int m,int k,vector<int>& bloomDay){
        int cnt=0;
        int bMade=0;
        for(int ind=0;ind<bloomDay.size();ind++){
            if(bloomDay[ind]<=day){
                cnt++;
                if(cnt==k){
                    cnt=0;
                    bMade++;
                }
            }
            else cnt=0;
        }
        return bMade>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long flowersNeeded=(long long)m* (long long)k;
        if(flowersNeeded > bloomDay.size()) return -1;
        int low=1e9,high=-1;
        for(auto day:bloomDay){
            low=min(day,low);
            high=max(day,high);
        }
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid,m,k,bloomDay)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};