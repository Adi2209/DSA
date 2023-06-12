class RandomizedSet {
private:
    //to store the value of ele->index
    unordered_map<int,int> mp;
    // to store the value of ele
    vector<int> nums;
    int size=0;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        else{
            mp[val]=size;
            nums.push_back(val);
            size++;
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        else{
            int index=mp[val];
            nums[index]=nums[size-1];
            nums.pop_back();
            size--;
            mp[nums[index]]=index;
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */