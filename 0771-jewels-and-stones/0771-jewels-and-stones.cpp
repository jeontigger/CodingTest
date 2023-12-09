class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> m;

        for(int i = 0; i<stones.length();i++){
            char c = stones[i];
            m[c]++;
        }

        int res = 0;
        for(int i = 0; i<jewels.size();i++){
            char c = jewels[i];
            res += m[c];
        }

        return res;
    }
};