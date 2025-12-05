class Solution {
public:
    int m_lower, m_upper;

    long long Counting(vector<long long>& sums, int left, int right) {
        if (left > right)
            return 0;
        if (left == right)
            return m_lower <= sums[left] && sums[left] <= m_upper;

        long long ret = 0;

        int mid = (left + right) / 2;
        ret += Counting(sums, left, mid);
        ret += Counting(sums, mid + 1, right);

        int lidx = left;
        long long loweridx = mid+1, upperidx = mid+1;
        while (lidx <= mid) {
            int i = lidx;
            long long lowerBound = m_lower + sums[i], upperBound = m_upper + sums[i];
            while(loweridx <= right && sums[loweridx] < lowerBound){
                loweridx++;
            }

            while(upperidx <= right && sums[upperidx] <= upperBound){
                upperidx++;
            }

            ret += (upperidx - loweridx);
            lidx++;
        }

        sort(sums.begin() + left, sums.begin() + right+1);

        return ret;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        m_lower = lower;
        m_upper = upper;
        int N = nums.size();
        vector<long long> sums(N);
        sums[0] = nums[0];
        for (int i = 1; i < N; i++) {
            sums[i] = sums[i - 1] + nums[i];
        }

        return Counting(sums, 0, N - 1);
    }
};