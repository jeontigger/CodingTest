class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        vector<int> consume(gas.size());

        int sum = 0;
        for(int i =0; i<gas.size();i++){
            sum += consume[i] = gas[i] - cost[i];
        }

        if(sum <0){
            return -1;
        }

        int res = 0;
        sum = 0;
        for(int i = 0; i < consume.size(); i++){
            sum += consume[i];
            if(sum < 0){
                sum = 0;
                res = i + 1;
            }
        }

        return res;
    }
};