class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        
        for(auto it:word1) mp1[it]++;
        for(auto it:word2) mp2[it]++;
        
        for(char i = 'a'; i<='z'; i++) {
             for(char j = 'a'; j<='z'; j++) {
                   if(mp1.count(i) && mp2.count(j)) {
                         mp1[i]--;   // remove i from mp1
                         if(mp1[i]==0) mp1.erase(i);   
                         mp1[j]++;
                         mp2[j]--;
                         if(mp2[j]==0) mp2.erase(j);
                         mp2[i]++;
                         if(mp1.size() == mp2.size()) return true;  // check if number of distinct chars is same
                         
                         // restoring the original state of the maps
                         mp1[j]--;
                         if(mp1[j]==0) mp1.erase(j);
                         
                         mp2[i]--;
                         if(mp2[i]==0) mp2.erase(i);
                         
                         
                         mp1[i]++;
                         mp2[j]++;
                   }
             }
         }
         return false;
    }
};