class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.length();
        
        stack<string> st;
        
        for(int i=0;i<n;i++){
            string word;
            if(s[i]==' '){
                continue;
            }
            while(i<n && s[i]!=' '){
                word+=s[i];
                i++;
            }
            st.push(word);
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()) ans+=' ';
        }
        return ans;
    }
};