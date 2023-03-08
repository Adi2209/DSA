class Solution {
    
    bool isPossible(vector<int>& piles, int k,int h){

        long long hours = 0;
        for(int pile : piles){
            long long div = pile / k;
            hours += div;
            if(pile % k != 0) hours++;
        }
        return hours <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n=piles.size();
        int s=1;
        int maxi=0;
        
        for(int i=0;i<n;i++){
            if(maxi<piles[i]) maxi=piles[i];
                
        }
        int e=maxi;
        // cout<<e<<endl;
        while(s<=e){
            int mid=s+(e-s)/2;
            
            if(isPossible(piles,mid,h)){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        
        return s;
        
    }
};