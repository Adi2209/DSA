class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int,int>> st;
        int n=s.size();
        for(int ind=0;ind<n;ind++){
            if(!st.empty() && s[ind]==st.top().first)
                st.top().second++;
            else{
                st.push({s[ind],1});
            }
            if(st.top().second==k){
                st.pop();
            }
        }
        string ans="";
        while(!st.empty()){
            auto tp=st.top();
            st.pop();
            while(tp.second--){
                ans+=tp.first;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};