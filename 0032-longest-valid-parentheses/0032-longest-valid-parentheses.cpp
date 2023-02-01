class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<int> st;
        int maxLen=0;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                //closing bracket found
                st.pop();
                //now new set of valid parenthesis will start from here 
                if(st.empty()) st.push(i);
                else{
                    //calculating the len from old valid parenthesis streak
                    int currLen=i-st.top();
                    maxLen=max(maxLen,currLen);
                }
            }
        }
        return maxLen;
    }
};