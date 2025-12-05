class Solution {
public:
    // 2진수화 -> 뒤집기 -> 10진수화

    string ToBinary(int num){
        string ret = "";

        for(int i = 0 ; i < 32; i++){
            int rem = num % 2;
            ret = to_string(rem) + ret;
            num /= 2;
        }
        return ret;
    }

    int ReverseAndDec(const string& str){
        int ret = 0;

        // cout << str << ' ';
        for(int i = 0 ; i < str.size(); i++){
            ret += (str[i] - '0') * pow(2, i);
        }

        return ret;
    }

    int reverseBits(int n) {
        string bin = ToBinary(n);

        int ret = ReverseAndDec(bin);
        return ret;
    }
};