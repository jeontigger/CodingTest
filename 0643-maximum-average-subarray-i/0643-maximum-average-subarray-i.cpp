class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double sum = 0, ret = -1e12;

        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            if (right - left + 1 == k) {
                ret = max(ret, sum);
                // cout << left << ' ' << right << ' ' << sum << '\n';

                sum -= nums[left++];
            }
        }

        return ret / k;
    }
};