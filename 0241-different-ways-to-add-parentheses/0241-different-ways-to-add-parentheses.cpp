class Solution {
public:
    vector<int> GetResults(string expression) {
        vector<int> res;
        bool justOne = true;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' || expression[i] == '-' ||
                expression[i] == '*') {
                justOne = false;
                // cout << expression.substr(0, i) << " " <<
                // expression.substr(i+1) << endl;
                auto r1 = GetResults(expression.substr(0, i));
                auto r2 = GetResults(expression.substr(i + 1));

                for (int i1 : r1) {
                    for (int i2 : r2) {
                        if (expression[i] == '+') {
                            res.push_back(i1 + i2);
                        }else if(expression[i] == '-'){
                            res.push_back(i1 - i2);
                        }else{
                            res.push_back(i1 * i2);
                        }
                    }
                }
            }
        }

        if (justOne) {
            // cout << stoi(expression) << " ";
            return {stoi(expression)};
        }

        return res;
    }

    vector<int> diffWaysToCompute(string expression) {
        return GetResults(expression);
    }
};