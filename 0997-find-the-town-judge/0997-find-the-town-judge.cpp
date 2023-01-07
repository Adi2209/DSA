class Solution{
public:
    int findJudge(int n, vector<vector<int>> &trust){
        unordered_map<int,int> trustTo;
        for (int i = 0; i < trust.size(); i++){
            trustTo[trust[i][0]]++;
        }
        unordered_map<int,int> trustedBy;
        for (int i = 0; i < trust.size(); i++){
            trustedBy[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(trustTo[i]==0 && trustedBy[i]==n-1)
                return i;
        }
        return -1;
    }
};