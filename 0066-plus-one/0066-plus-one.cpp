class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool plus = true;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (!plus)
                break;
            digits[i]++;
            plus = false;
            if (digits[i] == 10) {
                digits[i] = 0;
                plus = true;
            }
        }

        if(plus){
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};