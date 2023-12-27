class Solution {
public:
    void IntToBits(int num){
        for(int i =0; i<32;i++){
            cout << int((num >> (31 - i)) & 1);
        }
        cout << endl;
    }
    int bitAdd(int a, int b){
        int res = 0;
        for(int i = 0; i<32;i++){
            // int b1 = ((a & (1 << i));
            // int b2 = ((b & (1 << i));
            bool b1 = ((a >> i) & 1);
            bool b2 = ((b >> i) & 1);
            bool cur = ((res >> i) & 1);
            // cout << bool((b1 ^ b2 ^ cur));
            res &= ~(1 << i);
            res |= (b1 ^ b2 ^ cur) << i;
            if(i == 31){
                break;
            }
            res |= ((b1 & b2) | (b1 & cur) | (b2 & cur)) << i + 1;
            // IntToBits(res);
        }
        return res;
    }
    int getSum(int a, int b) {
        // IntToBits(a);
        // IntToBits(b);
        // cout << "=====================" << endl;
        return bitAdd(a, b);
    }
};