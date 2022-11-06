class Solution {
public:
    string largestPalindromic(string num) {
        
        vector<int> mp(10);
        
        for(auto i:num) mp[i-'0']++;
        string left,right;
        for(int i =9;i>=0;i--){
            if(i==0 && left.size()==0) continue;
                while(mp[i]>1){
                    left+=to_string(i);
                    right+=to_string(i);
                    mp[i]-=2;
                }
            }
        
        for(int i=9;i>=0;i--){
            if(mp[i]){
                left+=to_string(i);
                break;
            }
        }
        reverse(right.begin(),right.end());
        
        return left + right ;
    }
};
