class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret = "";
        while(columnNumber != 0){
            columnNumber--;
            ret = char(columnNumber % 26 + 'A') + ret;
            columnNumber /= 26;
        }      

        return ret;
    }
};