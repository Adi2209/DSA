class Solution {
public:
    double average(vector<int>& salary) {
        
        double max = DBL_MIN;
        double min = DBL_MAX;
        double sum = 0;
        
        for(int i=0; i < salary.size(); i++){
            
            sum += salary[i];
            
            if(salary[i] < min)
               min = salary[i];
            
            if(salary[i] > max)
               max = salary[i];
            
        }
        
        
        sum = sum - min - max;
        return sum / (salary.size()-2);
           
        
    }
};