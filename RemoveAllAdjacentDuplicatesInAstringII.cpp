class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n=s.length();
        stack<pair<char,int>>st;
        
        for(int i=0;i<n;i++){
            if(st.empty() || st.top().first!=s[i]){
                st.push({s[i],1});
            }
            else{
                //so the char is same as of stack
                auto prev=st.top();
                st.pop();
                st.push({prev.first,prev.second+1});
            }
            if(st.top().second==k) st.pop();
        }
        string ans;
        
        while(!st.empty()){
            auto curr=st.top();
            st.pop();
            while(curr.second--){
                ans+=curr.first;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};