class Solution {
public:
    vector<string> m_vRes;

    void Recursive(int n, int open, int close, string str){
        if(close == n) {
            m_vRes.push_back(str);
            return;
        }

        if(open < n){
            Recursive(n, open+1, close, str + "(");
        }

        if(open > close){
            Recursive(n, open, close + 1, str + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        Recursive(n, 0, 0, "");
        return m_vRes;
    }
};