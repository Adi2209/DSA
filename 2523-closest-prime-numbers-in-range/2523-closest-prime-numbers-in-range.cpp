class Solution {
private:
    vector<int> getMinDiffPrime(vector<int>& allPrimes){
        int minDiff=1e9,n=allPrimes.size();
        int nums1=-1,nums2=-1;
        for(int ind=0;ind+1<n;ind++){
            int curr=ind;
            int next=ind+1;
            
            int currDiff=allPrimes[next]-allPrimes[curr];
            if(currDiff<minDiff){
                minDiff=currDiff;
                nums1=allPrimes[curr];
                nums2=allPrimes[next];
            }
        }
        return {nums1,nums2};
    }
    void storePrimes(vector<int>& allPrimes, vector<bool>& sieve,int left){
        int start=max(2,left);
        int n=sieve.size();
        for(int ind=start;ind<n;ind++){
            if(sieve[ind])
                allPrimes.push_back(ind);
        }
    }
    
    void markPrimes(vector<bool>& sieve,int left,int right){
        //marking all the multiples (sieve of eratosthenes)
        for(int ind=2;ind*ind<=right;ind++){
            if(sieve[ind]){
                for(int j=ind*ind;j<=right;j+=ind){
                    sieve[j]=false;
                }
            }
        }
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right+1,true);
        markPrimes(sieve,left,right);
        //sieve array is ready with all the primes unmarked
        
        vector<int> allPrimes;
        //storing all the primes
        storePrimes(allPrimes,sieve,left);
        
        //Now finding the pair of primes with minimum difference
        return getMinDiffPrime(allPrimes);
        
        
    }
};