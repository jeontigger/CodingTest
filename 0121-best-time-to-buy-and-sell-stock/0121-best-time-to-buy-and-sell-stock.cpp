class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int maxProfit = 0;
        int maxCursor = 0;
        for(int i = 0; i<prices.size()-1;i++){
            if(i >= maxCursor){
                if(prices[i] < prices[i+1]){
                    maxCursor = max_element(prices.begin()+i+1, prices.end()) - prices.begin();
                    cout << i << " " <<  maxCursor << endl;
                }
            }



            int profit = 0;
            if( i < maxCursor){
                profit = prices[maxCursor] - prices[i];
            }
            if(profit>maxProfit){
                maxProfit = profit;
            }
        }
        return maxProfit;
    }
};