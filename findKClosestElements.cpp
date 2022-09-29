class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        
        int N = A.size(), lo = 0, hi = N - 1;
        while (hi - lo + 1 > k)
            if (abs(A[hi] - x) >= abs(A[lo] - x))
                hi--;
            else
                lo++;
        vector<int> ans(A.begin() + lo, A.begin() + hi + 1);//iterates the array 
        return ans;
    }
};
