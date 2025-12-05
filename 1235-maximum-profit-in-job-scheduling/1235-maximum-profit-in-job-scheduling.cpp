class Solution {
public:
    class Work {
    public:
        int start;
        int end;
        int profit;
        // Data(int s, int e, int p):start(s), end(e), profit(p){}
    };

    struct cmp {
        bool operator()(const Work& w1, const Work& w2) {
            return w1.end < w2.end;
        }
    };

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int N = startTime.size();

        // [0 ~ i]까지의 최대 이익
        vector<int> dp(N + 1, 0);
        vector<Work> works(N + 1);
        for (int i = 1; i <= N; i++) {
            works[i].start = startTime[i - 1];
            works[i].end = endTime[i - 1];
            works[i].profit = profit[i - 1];
        }

        sort(works.begin(), works.end(), cmp());

        // for(const Work& w : works){
        //     cout << w.start << ' ' << w.end << ' ' << w.profit << '\n';
        // }
        // cout << '\n';

        for (int i = 1; i <= N; i++) {
            for (int j = i; j >= 0; j--) {
                // 스타트 시간이 j의 끝나는 시간과 같거나 이후여야 함
                if (works[j].end <= works[i].start){
                    dp[i] = max(dp[i-1], dp[j] + works[i].profit);
                    break;
                }
            }

            // for (int i : dp) {
            //     cout << i << ' ';
            // }
            // cout << '\n';
        }

        return dp[N];
    }
};