class Solution {
private:
    bool ifLetter(string s){
        for(auto i:s){
            if(i>=97 && i<=122) return true;
        }
        return false;
    }
public:
    int maximumValue(vector<string>& strs) {
        int maxi=-1;
        
        for(auto i:strs){
            if(ifLetter(i)){
                int len=i.size();
                maxi=max(maxi,len);
            }
            else
                maxi=max(maxi,stoi(i));
        }
        return maxi;
    }
};