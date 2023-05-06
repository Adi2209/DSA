//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        string s;
        s.push_back(str[0]);
        for(int i = 1; i < str.size(); i++){
            if(str[i]>str[i-1] && i!= 1)
                break;
            if(str[i]>=str[i-1] && i ==1) 
                break;
            s.push_back(str[i]);
        }
        int n = s.size();
        for(int i =n-1 ; i>=0; i--){
            s.push_back(s[i]);
        }
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends