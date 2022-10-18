class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        
        for(int i=2;i<=n;i++){
            string lastString=ans;
            
            int s=0;
            int j=ans.size();
            ans="";
            while(s<j){
                int cnt=s;
                while(s<j && lastString[s]==lastString[cnt]){
                    cnt++;
                }
                ans+=to_string(cnt-s)+lastString[s];
                s=cnt;
            }
        }
        return ans;
    }
};
