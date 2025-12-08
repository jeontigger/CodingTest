class Solution {
public:
    vector<vector<int>> ret;
    vector<int> m_cands;
    int m_target;
    int N;
    void DFS(int idx, int sum, vector<int>& comb) {
        if (sum == m_target) {
            ret.push_back(comb);
            return;
        }
        if (sum > m_target)
            return;

        int prev = -1;
        for (int i = idx; i < N; i++) {
            if (sum + m_cands[i] > m_target)
                break;
            if (prev == m_cands[i])
                continue;
            comb.push_back(m_cands[i]);
            DFS(i + 1, sum + m_cands[i], comb);
            comb.pop_back();
            prev = m_cands[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        m_target = target, N = candidates.size(), m_cands = candidates;
        vector<int> comb;
        DFS(0, 0, comb);

        return ret;
    }
};