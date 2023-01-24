class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool> allPrimes(n+1,false);
        allPrimes[0]=allPrimes[1]=true;
        
        
        for(int i=2;i*i<=n;i++){
            if(allPrimes[i]==false){
                for(int j=i*i;j<=n;j+=i){
                    allPrimes[j]=true;
                }
            }
        }
        int primes=0;
        for(int ind=2;ind<n;ind++){
            if(!allPrimes[ind])
                primes++;
        }
        return primes;
    }
};