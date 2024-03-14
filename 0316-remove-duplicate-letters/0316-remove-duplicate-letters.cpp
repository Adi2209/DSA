class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26,0);
        vector<bool> isPresent(26,false);
        stack<char> st;
        // getting the last index for the elements
        int size = s.length();
        for(int ind =0;ind<size;ind++){
            int ele = s[ind]-'a';
            lastIndex[ele] = ind;
        }
        
        for(int ind=0;ind<size;ind++){
            int ele = s[ind]-'a';
            if(isPresent[ele]) continue;
            while(st.size() > 0 && st.top() > s[ind] && ind< lastIndex[st.top()-'a']){
                isPresent[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[ind]);
            isPresent[ele] = true;
        }
        string ans = "";
        while (st.size() > 0){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};