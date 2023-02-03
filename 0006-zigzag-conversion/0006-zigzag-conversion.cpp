class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows==1)
            return s;
        bool down=false;
        vector<string> nums(numRows);
        
        int j=0;
        for(int i=0;i<s.length();i++){
            nums[j].push_back(s[i]);
            if(j==numRows-1)
                down=false;
            else if(j==0)
                down=true;
            
            if(down==true)
                j++;
            else
                j--;
        }
        string ans="";
        
        for(auto i:nums)
            ans+=i;
        
        return ans;
        
    }
};