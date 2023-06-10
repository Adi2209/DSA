//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
private:
    void solve(int ind,int sum,vector<int>& ans, vector<int> arr,int n){
        if(ind==n){
            ans.push_back(sum);
            return;
        }
        //include
         solve(ind+1,sum,ans,arr,n);
        solve(ind+1,sum+arr[ind],ans,arr,n);
        //exclude
       
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        solve(0,0,ans,arr,N);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends