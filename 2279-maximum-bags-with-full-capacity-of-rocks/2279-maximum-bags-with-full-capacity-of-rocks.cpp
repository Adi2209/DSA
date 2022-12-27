class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int n=rocks.size();
        vector<int> diff;
        
        for(int i=0;i<n;i++){
            int d=capacity[i]-rocks[i];
            diff.push_back(d);
        }
        sort(diff.begin(),diff.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            if(diff[i]==0){
                cnt++;
            }
            else if(diff[i]<=additionalRocks){
                cnt++;
                additionalRocks-=diff[i];
            }
            
        }
        return cnt;
    }
};