class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st;
        for(auto &it:nums) st.insert(it);
        
        //now we will traverse the set and check if the previous element is in the set or not 
        int longest=0;
        
        for(auto &it:st){
            int prevEle=it-1;
            if(st.find(prevEle)==st.end()){
                int cnt=1;
                int currEle=it;
                while(st.find(currEle+1)!=st.end()){
                    cnt++;
                    currEle+=1;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};