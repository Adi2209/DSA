class Solution {
private:
    int getMax(vector<int>& piles){
        int maxi=-1;
        for(auto &it:piles){
            maxi=max(it,maxi);
        }
        return maxi;
    }
    bool canEat(int k,int h,vector<int>& piles){
        long long hours=0;
        for(auto pile:piles){
            long long div=pile/k;
            hours+=div;
            if(pile%k!=0) hours++;
        }
        return hours<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high= getMax(piles);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canEat(mid,h,piles)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};