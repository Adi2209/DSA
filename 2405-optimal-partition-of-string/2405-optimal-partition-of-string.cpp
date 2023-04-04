class Solution {
public:
    int partitionString(string s) {
        int ans=1;
        set<char> st;
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])!=st.end()){
                st.clear();
                st.insert(s[i]);
                ans++;
                
            }
            else{
                st.insert(s[i]);
            }
        }
        return ans;
    }
};