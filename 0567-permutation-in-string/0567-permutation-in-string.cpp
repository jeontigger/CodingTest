class Solution {
public:
    int s1Cnts[26], s2Cnts[26];

    bool IsCanPermutating() {
        for (int i = 0; i < 26; i++) {
            if (s1Cnts[i] != s2Cnts[i])
                return false;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        for (int i = 0; i < s1.size(); i++) {
            s1Cnts[s1[i] - 'a']++;
        }

        int left = 0;
        for (int right = 0; right < s2.size(); right++) {
            s2Cnts[s2[right] - 'a']++;

            if (right - left + 1 > s1.size()) {
                s2Cnts[s2[left] - 'a']--;
                left++;
            }

            if (s2Cnts[s2[right] - 'a'] == s1Cnts[s2[right] - 'a']) {
                if (IsCanPermutating())
                    return true;
            }
        }

        return false;
    }
};