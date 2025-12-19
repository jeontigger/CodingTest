class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for (int i = 1; i <= n; i++) {
            string str = "";
            if (i % 3 != 0 && i % 5 != 0) {
                str += to_string(i);
            } else {
                if (i % 3 == 0)
                    str += "Fizz";
                if (i % 5 == 0)
                    str += "Buzz";
            }
            ret.push_back(str);
        }
        return ret;
    }
};