class Solution {
private:
    vector<int> getLeftSmall(vector<int>& heights,stack<int>& st){
        int n=heights.size();
        vector<int> leftSmall(n);
        for(int ind=0;ind<n;ind++){
            while(!st.empty() && heights[st.top()]>= heights[ind]) st.pop();
            if(st.empty()) leftSmall[ind]=0;
            else leftSmall[ind]=st.top()+1;
            st.push(ind);
        }
        return leftSmall;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        //calculating leftSmall area
        vector<int> leftSmall=getLeftSmall(heights,st);
        //clearing the stack, to use for rightSmall and calculating max area
        while(!st.empty()) st.pop();
        
        vector<int> rightSmall(n);
        for(int ind=n-1;ind>=0;ind--){
            while(!st.empty() && heights[st.top()]>= heights[ind]) st.pop();
            if(st.empty()) rightSmall[ind]=n-1;
            else rightSmall[ind]=st.top()-1;
            st.push(ind);
        }
        int maxArea=0;
        for(int ind=0;ind<n;ind++){
            maxArea=max(maxArea,heights[ind]* (rightSmall[ind]-leftSmall[ind]+1));
        }
        return maxArea;
    }
};