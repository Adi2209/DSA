/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    void checkEmployee(int id,unordered_map<int,Employee*> &mp,int &totalImportance){
        
        totalImportance+=mp[id]->importance;
        
        for(auto &it:mp[id]->subordinates){
            checkEmployee(it,mp,totalImportance);
        }
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        unordered_map<int,Employee*> mp;
        for(auto it:employees){
            mp[it->id]=it;
        }
        int totalImportance=0;
        checkEmployee(id,mp,totalImportance);
        return totalImportance;
    }
};