class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n=s.size();
        for(int ind=0;ind<n;ind++){
            if(!st.empty() && st.top()==s[ind]) st.pop();
            else st.push(s[ind]);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};