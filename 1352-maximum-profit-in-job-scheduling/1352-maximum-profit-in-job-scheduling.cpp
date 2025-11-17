class Solution {
public:
    struct Work {
        int start;
        int end;
        int profit;
    };

    static bool cmp(const Work& w1, const Work& w2) {
        return w1.end < w2.end;   // 끝나는 시간 기준 정렬
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int N = startTime.size();
        vector<Work> works(N);
        for (int i = 0; i < N; ++i) {
            works[i] = { startTime[i], endTime[i], profit[i] };
        }

        // 1) 종료 시간 기준 정렬
        sort(works.begin(), works.end(), cmp);

        // 2) end값만 따로 뽑아서 이진 탐색용 배열 생성
        vector<int> ends(N);
        for (int i = 0; i < N; ++i) {
            ends[i] = works[i].end;
        }

        // 3) dp[i] = 0..i번째 작업까지 고려했을 때의 최대 이익 (i는 0-based)
        vector<int> dp(N, 0);
        dp[0] = works[0].profit;

        for (int i = 1; i < N; ++i) {
            // i번째 일을 선택하는 경우의 이익
            int take = works[i].profit;

            // i번째 일을 하기 전에 할 수 있는 마지막 작업 인덱스(prev)를 찾는다
            int idx = upper_bound(ends.begin(), ends.begin() + i, works[i].start)
                      - ends.begin() - 1;

            if (idx >= 0) {
                take += dp[idx];
            }

            // i번째 일을 안 하는 경우 = dp[i-1]
            int skip = dp[i - 1];

            dp[i] = max(skip, take);
        }

        return dp[N - 1];
    }
};
