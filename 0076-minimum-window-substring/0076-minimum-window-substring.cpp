class Solution {
public:
    bool IsInclude(unordered_map<char, int>& m1, unordered_map<char, int>& m2) {
        for (auto iter = m2.begin(); iter != m2.end(); ++iter) {
            if (m2[iter->first] > m1[iter->first]) {
                return false;
            }
        }
        return true;
    }

    unordered_map<char, int> m;
    unordered_map<char, int> mt;
    string minWindow(string s, string t) {

        for (int i = 0; i < t.length(); i++) {
            mt[t[i]]++;
        }

        int left = 0;
        int len = 1e9;
        string answer = "";
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;

            // if(IsInclude(m, mt)){
            //     while(mt[s[left]] != 0){
            //         m[s[left]]--;
            //         if(i - left< len){
            //             answer = s.substr(left, i - left+1);
            //             len = min(len, i - left+1);
            //         }
            //         left++;
            //     }
            // }

            bool include = false;
            while (IsInclude(m, mt)) {
                m[s[left]]--;
                include = true;
                left++;
                // cout << "in ";
            }

            if (include) {
                if (i - left < len) {
                    answer = s.substr(left-1, i - left + 2);
                    len = min(len, i - left + 1);
                }
            }
        }

        return answer;
    }
};