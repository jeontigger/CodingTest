class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;

        int left =0;
        int right = 0;
        int maxCnt = 0;
        int res = -1;

        while(right < s.length()){

            map[s[right]]++;

            maxCnt = max(maxCnt, map[s[right]]);

            int len = right - left + 1;
            if(len - maxCnt > k){
                map[s[left]]--;
                left++;
            }

            len = right - left + 1;
            res = max(len, res);

            right++;
        }

        return res;
    }
};