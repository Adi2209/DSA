class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
    
        for(auto it:asteroids){
            if(it>0) st.push(it);
            else{
                // when top is less than it
                while(!st.empty() && st.top()>0 && st.top() < -it){
                    st.pop();
                }
                //when both of same size
                if(!st.empty() && st.top()==-it) st.pop();
                else if(!st.empty() && st.top()>-it) continue;
                //when in same direction
                else st.push(it);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};