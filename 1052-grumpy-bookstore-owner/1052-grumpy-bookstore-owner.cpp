class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ret = 0, left = 0, notGrumpySum = 0;

        for (int i = 0; i < customers.size(); i++) {
            notGrumpySum += grumpy[i] ? 0 : customers[i];
        }

        int grumpySum = 0;
        for (int right = 0; right < customers.size(); right++) {
            grumpySum += grumpy[right] ? customers[right] : 0;

            if (right - left + 1 > minutes) {
                grumpySum -= grumpy[left] ? customers[left] : 0;
                left++;
            }

            ret = max(ret, grumpySum);
        }

        return ret + notGrumpySum;
    }
};