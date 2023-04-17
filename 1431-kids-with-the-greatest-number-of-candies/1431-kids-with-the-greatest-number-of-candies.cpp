class Solution {    
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<bool> ans;
        
    
        int maxi=INT_MIN;
        
        for(int i=0;i<candies.size();i++){
            
            if(candies[i]>maxi){
                maxi=candies[i];
            }
        }
        
        for(int j=0;j<candies.size();j++){
            if(extraCandies+candies[j]>=maxi){
                ans.push_back(true);
            }
            else
                ans.push_back(false);
        }
        return ans;
    }
};