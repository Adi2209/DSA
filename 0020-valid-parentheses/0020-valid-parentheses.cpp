class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        for(int ind=0;ind<n;ind++){
            if(s[ind]=='(' || s[ind]=='{' || s[ind]=='['){
                st.push(s[ind]);
                continue;
            }
            if(st.empty()) return false;
            int tp=st.top();
            if( (tp=='(' && s[ind]==')') || (tp=='{' && s[ind]=='}') || (tp=='[' && s[ind]==']')) st.pop();
            else return false;
        }
        if(st.empty()) return true;
     return false;
    }
};