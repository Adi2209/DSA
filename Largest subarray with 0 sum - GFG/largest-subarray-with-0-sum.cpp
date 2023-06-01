//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int k=0;
        int maxi=0,sum=0;
        unordered_map<int,int> mp;
        for(int ind=0;ind<n;ind++){
            sum+=A[ind];
            if(sum==k) maxi=max(maxi,ind+1);
            
            if(mp.find(sum-k)!=mp.end()){
                maxi=max(maxi,ind-mp[sum-k]);
            }
            else mp[sum-k]=ind;
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends