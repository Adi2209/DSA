class Solution {
private:
    long long tripTaken(vector<int>& time,long long secs){
        
        long long cnt=0;
        
        for(int i=0;i<time.size();i++){
            cnt+=secs/time[i];
        }
        return cnt;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long s=0;
        long long e=1e14;
        long long ans=-1;
        
        while(s<=e){
            long long mid=s+(e-s)/2;
            
            if(tripTaken(time,mid)>=totalTrips){
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        
        return ans;
    }
};