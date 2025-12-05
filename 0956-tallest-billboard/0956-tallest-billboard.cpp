class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        // 최대 => sum/2;
        // 두 서브셋의 합이 같은 가장 큰 수
        // 1집단에 넣을수도, 2집단에 넣을수도 있음
        // [차이] = 낮은 쪽 높이의 최대값
        // [현재idx], 현재 val,
        // 현재 차이에서 큰 쪽에 넣기 -> [현재idx+현재val]에다가

        unordered_map<int, int> dp;
        dp[0] = 0;
        for (int rod : rods) {
            // 이번 rod를 쓰기 전의 상태를 복사
            auto cur = dp;

            for (auto [diff, low] : cur) {
                // 높은 쪽 더하기
                dp[diff + rod] = max(dp[diff + rod], low);

                // 낮은 쪽 더하기
                if (diff >= rod) {
                    dp[diff - rod] = max(dp[diff - rod], low + rod);
                } else {
                    dp[rod - diff] = max(dp[rod - diff], low + diff);
                }
            }
        }

        return dp[0];
    }
};