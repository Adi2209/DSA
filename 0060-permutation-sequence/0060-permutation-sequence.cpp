class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> numbers;
        for(int ind=1;ind<n;ind++){
            fact*=ind;
            numbers.push_back(ind);
        }
        numbers.push_back(n);
        string ans="";
        k--;
        while(true){
            ans=ans+to_string(numbers[k/fact]);//number which will form the next digit will be added to the ans
            numbers.erase(numbers.begin()+k/fact);//erase the number which is processed
            if(numbers.size()==0) break;
            k=k%fact;
            fact=fact/numbers.size();
            
        }
        return ans;
    }
};