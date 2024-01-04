class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        
        for(int i = 0; i < input.length(); i++){
            char c = input[i];

            if(c == '+' || c == '-' || c == '*'){
                auto lefts = diffWaysToCompute(input.substr(0, i));
                auto rights = diffWaysToCompute(input.substr(i+1));

                for(int left : lefts){
                    for(int right : rights){
                        if(c=='+'){
                            result.push_back(left+right);
                        }else if (c == '-'){
                            result.push_back(left-right);
                        }else if(c == '*'){
                            result.push_back(left*right);
                        }
                    }
                }
            }
        }

        if(result.empty()){
            result.push_back(stoi(input));
        }


        return result;
    }
};