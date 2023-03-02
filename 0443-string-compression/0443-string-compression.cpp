class Solution {
public:
    int compress(vector<char>& chars) {
        
        int i=0;
        int n=chars.size();
        
        int ansindex=0;
        
        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
                j++;
            }
            //yahan pe tabh hi aaoge jab poora array traverse kar liya 
            //yaa koi different char aagya
            
            //old char store karlo pehle
            
            
            chars[ansindex++]=chars[i];
            
            int count=j-i;
            
            if(count >1){
                //converting the count to string and saving in the answer
                
                string cnt=to_string(count);
                for(char ch:cnt){
                    chars[ansindex++]=ch;
                }
            }
            //moving to new or diff charecter ..uske aage jaate hue jahan tak same tha
            i=j;
        }
        return ansindex;
    }
};