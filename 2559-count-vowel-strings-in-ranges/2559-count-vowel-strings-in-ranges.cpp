class Solution {
private:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'; 
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<long long> prefix(n+1,0);
        for(int ind=0;ind<n;ind++){
            char first=words[ind][0];
            char last=words[ind][words[ind].size()-1];
            if(isVowel(first) && isVowel(last)){
                prefix[ind+1]=prefix[ind]+1;
            }
            else prefix[ind+1]=prefix[ind];
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int end=queries[i][1];
            int cnt=prefix[end+1]-prefix[start];
            ans.push_back(cnt);
        }
        return ans;
    }
};