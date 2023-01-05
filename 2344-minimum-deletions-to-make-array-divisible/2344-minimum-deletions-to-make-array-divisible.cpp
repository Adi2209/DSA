class Solution {
private:
    bool isDividing(int n,vector<int>& numsDivide){
        
        for(auto it:numsDivide){
            if(it%n!=0) return false;
        }
        return true;
    }
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int,int> mp;
        for(auto it:nums)mp[it]++; 
        int del=0;
        bool flag=false;
        for(auto it :mp){
            if(isDividing(it.first,numsDivide)){
                flag=true;
                break;
            }
            else
                del+=it.second;
        }
        if(flag) return del;
        return -1;
    }
};