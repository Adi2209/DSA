class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int customerSize = customers.size();
        int currTime = customers[0][0]+customers[0][1]; // 7
        double waitingTime = (double) currTime - customers[0][0]; // 5
        if(customerSize == 1) return waitingTime;
        for(int ind = 1;ind<customerSize;ind++){
            if(currTime<customers[ind][0]){
                currTime = customers[ind][0]+customers[ind][1];
                waitingTime += currTime - customers[ind][0];
                cout<<"WaitingTime: if   "<<waitingTime<<" ind: "<<ind<<endl;

            }
            else{
            currTime+=customers[ind][1];
            waitingTime+=currTime-customers[ind][0];
            cout<<"WaitingTime: "<<waitingTime<<" ind: "<<ind<<endl;
            }

        }
        return waitingTime/( double) customerSize;
    }
};