class Solution {
private:
    int getSum(vector<int>& weights){
        int sum=0;
        for(auto it:weights){
            sum+=it;
        }
        return sum;
    }
    bool canShip(int capacity,vector<int>& weights,int threshold){
        int load=0;
        int days=1;
        for(int ind=0;ind<weights.size();ind++){
            if(load+weights[ind]>capacity){
                load=weights[ind];
                days++;
            }
            else{
                load+=weights[ind];
            }
            if(days>threshold) return false;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=getSum(weights);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canShip(mid,weights,days)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};