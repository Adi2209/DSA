class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0,right=0,n=fruits.size(),ans=0;
        unordered_map<int,int> mp;
        
        while(right<n){
            // expanding the window from right
            mp[fruits[right]]++;
            if(mp.size()<=2)
                ans=max(ans,right-left+1);
            else{
                //shrinking the window from left
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0) mp.erase(fruits[left]);
                left++;
            }
            right++;
        }
        return ans;
    }
};