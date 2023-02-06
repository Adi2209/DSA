class Solution {
    vector<int> arr;
    int size;
public:
    Solution(vector<int>& nums){
        size=nums.size();
        arr=nums;
    }
    
    vector<int> reset(){
        return arr;
    }

    vector<int> shuffle(){
        vector<int> temp = arr;
        int mod = size;
        for(int i = size - 1; i >= 0; --i){
            int pos = rand() % mod;
            swap(temp[i], temp[pos]);
            mod--;
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */