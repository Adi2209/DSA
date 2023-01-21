class Solution {
public:
    bool isValid(string s){
        int n=s.size();
        
        if(n==1) return true;
        if(n>3||s[0]=='0') return false;
        
        int intVal=stoi(s);
        if(intVal>255) return false;
        
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string>ans;
        if(n>12){
            return ans;
        }
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    //checking condition if the last segment is of length 3 or less
                    if(i+j+k<n&&i+j+k+3>=n){
                        //dividing the s into substrings of 4 parts just like the IP Address
                        string first=s.substr(0,i);
                        string second=s.substr(i,j);
                        string third=s.substr(j+i,k);
                        string fourth=s.substr(i+j+k);
                        //checking the valid condition
                        if(isValid(first)&&isValid(second)&&isValid(third)&&isValid(fourth)){
                            ans.push_back(first+"."+second+"."+third+"."+fourth);
                        }
                    }
                }
            }
        }
        return ans;
    }
};