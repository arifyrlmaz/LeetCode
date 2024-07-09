class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time=0;
        double count=0;
        int temp=0;
        time=customers[0][0];
        for(int i = 0 ; i<customers.size();i++){
            if(time < customers[i][0]){
                time=customers[i][0];
            }
            if(time >= customers[i][0]){
time = time + customers[i][1];
            }
            
            count = count + (time-customers[i][0]);  
        } 
        return count/customers.size();

    }
};