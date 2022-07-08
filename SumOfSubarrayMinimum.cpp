class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> pge(n);
        vector<int> nge(n);
        
        stack<int> st;
        
        //finding the previous greater element 
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]> arr[i]) st.pop();
            
            if(!st.empty()){
                pge[i]=i-st.top();
            }
            else
                pge[i]=i+1;
            st.push(i);
        }
        //emptying the stack to use for nge
        while(!st.empty()) st.pop();
        
        //finding the next greater element
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()){
                nge[i]=st.top()-i;
            }
            else{
                nge[i]=n-i;
            }
            st.push(i);
        }
         int res = 0;
        int MOD=1e9+7;
        for(int i=0; i<n; i++)
        {
            long long prod = (pge[i]*nge[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }
        
        return res%MOD;
        
    }
};