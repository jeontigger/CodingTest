class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> window;
        vector<int> ret;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            window.insert(
                lower_bound(window.begin(), window.end(), nums[right]),
                nums[right]);

            if (right - left + 1 == k) {
                int val = window.back();
                
                ret.push_back(val);

                window.erase(
                    lower_bound(window.begin(), window.end(), nums[left]));
                left++;
            }
        }

        return ret;
    }
};