class Solution {
public:
    vector<char> two = {'a', 'b', 'c'};
    vector<char> three = {'d', 'e', 'f'};
    vector<char> four = {'g', 'h', 'i'};
    vector<char> five = {'j', 'k', 'l'};
    vector<char> six = {'m', 'n', 'o'};
    vector<char> seven = {'p', 'q', 'r', 's'};
    vector<char> eight = {'t', 'u', 'v'};
    vector<char> nine = {'w', 'x', 'y', 'z'};
    vector<vector<char>> vecs = {two, three, four, five, six, seven, eight, nine};
    vector<string> letterCombinations(string digits) {
        vector<string> vec;
        if(digits == ""){
            return vec;
        }
        
        int combCnt = 1;
        for(int i = 0; i<digits.length();i++){
            if(digits[i] == '9'|| digits[i] == '7'){
                combCnt *= 4;
            }else{
                combCnt *= 3;
            }
        }

        cout << combCnt << endl;

        vec.resize(combCnt);
        int div = combCnt;
        for(int i =0; i<digits.length();i++){
            char c = digits[i];
            vector<char>* pVec;
            pVec = &vecs[c-'2'];
            
            div /= pVec->size();
            if (div <= 0){
                div = 1;
            }
            for(int j = 0; j<vec.size();j++){
                // 0~27 / (27 / 몫) % size;
                vec[j] += (*pVec)[ ( j  / div) % pVec->size()];
            }
        }




        return vec;
    }
};