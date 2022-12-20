class Solution {
public:
    int similarPairs(vector<string>& words) {
        int cnt=0;
        vector<string> res;
        for(auto i:words){
            set<char> st;
            for(auto j:i) st.insert(j);
            string temp="";
            for(auto k:st) temp+=k;
            res.push_back(temp);
        }
        for(int i =0;i<res.size();i++){
            for(int j=i+1;j<res.size();j++){
                if(res[i]==res[j]) cnt++;
            }
        }
        return cnt;
    }
};