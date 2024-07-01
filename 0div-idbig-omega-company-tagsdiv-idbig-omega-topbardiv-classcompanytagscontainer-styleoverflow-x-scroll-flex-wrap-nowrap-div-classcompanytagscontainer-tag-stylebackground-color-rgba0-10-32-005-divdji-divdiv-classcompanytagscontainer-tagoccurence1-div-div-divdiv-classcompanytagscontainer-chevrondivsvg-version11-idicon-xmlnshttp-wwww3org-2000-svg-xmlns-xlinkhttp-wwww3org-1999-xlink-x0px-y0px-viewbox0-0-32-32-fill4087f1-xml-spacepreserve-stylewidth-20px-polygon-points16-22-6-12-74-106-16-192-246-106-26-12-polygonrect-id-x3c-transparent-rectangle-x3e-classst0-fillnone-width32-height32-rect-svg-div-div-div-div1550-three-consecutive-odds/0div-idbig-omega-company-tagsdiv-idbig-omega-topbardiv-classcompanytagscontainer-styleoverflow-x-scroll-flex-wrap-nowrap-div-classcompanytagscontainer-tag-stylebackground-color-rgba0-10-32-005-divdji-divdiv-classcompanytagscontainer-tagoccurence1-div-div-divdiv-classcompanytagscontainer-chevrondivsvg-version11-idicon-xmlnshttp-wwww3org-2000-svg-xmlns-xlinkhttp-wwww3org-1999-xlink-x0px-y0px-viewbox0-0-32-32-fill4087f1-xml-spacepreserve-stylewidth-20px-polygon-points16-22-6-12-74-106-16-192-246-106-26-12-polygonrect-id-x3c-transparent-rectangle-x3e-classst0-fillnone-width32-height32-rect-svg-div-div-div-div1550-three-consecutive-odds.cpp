class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int size = arr.size();
        int consecutiveOdds = 0;
        for(int ind = 0;ind<size;ind++){
            if(arr[ind]%2!=0){
                consecutiveOdds++;
            }
            if (consecutiveOdds<3 && arr[ind]%2==0){
                consecutiveOdds = 0;
            }
            if(consecutiveOdds>=3) return true;
                
        }
        return false;
    }
};