**TLE CODE:**
​
```
class Solution {
private:
bool isTrue(string& s){
unordered_map<char,int> mp;
for(auto it:s) mp[it]++;
bool flagA=false,flagB=false,flagC=false;
for(auto it: mp){
if(it.first=='a') flagA=true;
if(it.first=='b') flagB=true;
if(it.first=='c') flagC=true;
}
return flagA && flagB && flagC;
}
public:
int numberOfSubstrings(string s) {
int cnt=0;
for(int i = 0; i < s.length(); i++){
string subStr;
for(int j = i; j < s.length(); j++){
subStr += s[j];
if(isTrue(subStr)) cnt++;
}
}
return cnt;
}
};
```