class Solution {
private:
    void getCombinations(int ind,int &k,vector<vector<int>>& allCombinations,int sum,vector<int>& res){
        //base case
        if(k==res.size()){
            if(sum==0){
                allCombinations.push_back(res);
                return;
            }
        }
        for(int idx=ind;idx<=9;idx++){
            res.push_back(idx);
            getCombinations(idx+1,k,allCombinations,sum-idx,res);
            res.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> allCombinations;
        vector<int> res;
        getCombinations(1,k,allCombinations,n,res);
        return allCombinations;
    }
};