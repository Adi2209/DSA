class Solution {
private:
     bool cmp(vector<int>& arr1,vector<int>& arr2){
        return arr1[targetCol]>arr2[targetCol];
    }
public:
    int targetCol;
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        targetCol=k;
        sort(score.begin(), score.end(), [this](vector<int> a, vector<int> b) { return cmp(a,b); });
        return score;
    }
};