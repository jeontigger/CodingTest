class Solution {
public:
    int N, K;
    int sum = 0, target = 0;
    vector<int> m_nums, visited;
    bool DFS(int cur, int idx, int group) {
        if (group == K - 1)
            return true;
        if (cur == target) {
            return DFS(0, 0, group + 1);
        }

        for (int i = idx; i < N; i++) {
            if (!visited[i]) {
                if (cur + m_nums[i] <= target) {
                    visited[i] = true;
                    if(DFS(cur + m_nums[i], i + 1, group)) return true;
                    visited[i] = false;
                }
            }
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        m_nums = nums;
        N = nums.size(), K = k;
        
        visited.resize(N);
        for (int num : nums)
            sum += num;

        target = sum / k;

        if (sum % k != 0 || nums[0] > target)
            return false;

        return DFS(0, 0, 0);
    }
};