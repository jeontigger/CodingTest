class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string before = countAndSay(n - 1);
        string ret = "";

        int sequence = 0;
        int cur = 0;
        for (int i = 0; i < before.size(); i++) {
            if (cur != before[i]) {
                if (sequence > 0)
                    ret += to_string(sequence) + (char)cur;
                cur = before[i];
                sequence = 1;
            } else {
                sequence++;
            }
        }
        if (sequence > 0) {
            ret += to_string(sequence) + (char)cur;
        }

        return ret;
    }
};