class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int diff = x^y;
        for(int i =0; i<32;i++){
            res += diff&0x00000001;
            diff >>= 1;
        }
        return res;
    }
};