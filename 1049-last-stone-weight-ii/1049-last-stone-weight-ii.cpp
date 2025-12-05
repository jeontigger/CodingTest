
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // P + N = sum;
        // N = sum - P;
        // P - N = 2*P - sum 이 가장 작아지는 
        // 
        int S = accumulate(stones.begin(), stones.end(), 0);
        vector<char> dp(S + 1, 0);
        dp[0] = 1;
        for (int w : stones) {
            for (int j = S; j >= w; --j) {
                dp[j] = dp[j] | dp[j - w];
            }
        }
        int best = 0;
        for (int s = S / 2; s >= 0; --s) {
            if (dp[s]) { best = s; break; }
        }
        return S - 2 * best;
    }
};