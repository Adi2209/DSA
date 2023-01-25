class Solution {
private:
    bool isValid(string query,string pattern){
        
        int i=0,j=0;
        while(i<query.size() || j<pattern.size()){
            if(query[i]==pattern[j]){
                i++;
                j++;
            }
            else if(query[i]>='a' && query[i]<='z'){
                i++;
            }
            else{
                //in case of an uppercase encounter 
                return false;
            }
        }
        return true;
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        
        for(auto query:queries){
            ans.push_back(isValid(query,pattern));
        }
        return ans;
    }
};