class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 0; i < prices.size() - 1;i++){
            int buy = prices[i];
            int sell = prices[i+1];

            int profit = sell - buy;

            if(profit > 0){
                res += profit;
            }
        }

        return res;
    }
};