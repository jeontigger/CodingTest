class Solution {
public:
    int sCnts[128];
    unordered_map<char, int> tCnts;

    bool IsSubstring() {

        for (auto& [c, cnt] : tCnts) {
            if (sCnts[c] < cnt)
                return false;
        }

        return true;
    }

    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        for (char c : t) {
            tCnts[c]++;
        }

        string ret = "";
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            sCnts[s[right]]++;

            if (IsSubstring()) {

                while (IsSubstring()) {
                    sCnts[s[left]]--;
                    left++;
                }

                if (ret == "" || right - left + 1 < ret.size()) {
                    ret = s.substr(left - 1, right - left + 2);
                }
            }
        }

        return ret;
    }
};