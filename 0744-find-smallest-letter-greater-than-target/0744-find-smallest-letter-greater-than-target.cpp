class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0,high=letters.size()-1;
        while(low<=high){
            int mid=(low+high+1)/2;
            if(mid<letters.size()-1 && letters[mid]<= target && letters[mid+1]>target)   
                return letters[mid+1];
            else if(letters[mid]<= target)   low=mid+1;
            else high=mid-1;
        }
        return letters[0];
    }
};