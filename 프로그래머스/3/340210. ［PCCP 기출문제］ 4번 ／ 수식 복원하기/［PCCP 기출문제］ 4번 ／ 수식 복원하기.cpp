#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int DecToBase(int n, int num){
    int res = 0;
    int loop = 1;
    
    while(num){
        res += (num % 10) * loop;
        loop *= n;
        num /= 10;
    }
    
    return res;
}
string DecToBaseString(int n, int num){
    string res = "";
    
    do{
        res = (char)((num % n) + '0') + res;
        num /= n;
    }while(num);
    
    return res;
}

int GetMaxBase(string& input){
    int cnt = 0;
    istringstream iss(input);
    string str;
    int maxValue = 0;
    while(iss >> str){
        cnt++;
        if(cnt %2 == 0) continue;

        for(int j = 0;  j < str.size(); j++){
            if(str[j] == 'X') continue;
            maxValue = max(maxValue, str[j] - '0');
        }
    }
    
    return maxValue;
}

int GetMaxBase(vector<string>& v){
    int maxValue = 0;
    
    string str;
    for(int i = 0 ; i < v.size(); i++){
        maxValue = max(maxValue, GetMaxBase(v[i]));
        // cout << endl;
    }
    
    return maxValue + 1;
}

bool FindBase(vector<string>& v, int& base){
    if(base == 9) return true;
    string str;
    for(int i = 0 ; i < v.size(); i++){
        istringstream iss(v[i]);
        
        iss >> str;
        int left = stoi(str);
        
        iss >> str;
        char op = str[0];
        
        iss >> str;
        int right = stoi(str);
        
        iss >> str;
        
        iss >> str;
        int res = stoi(str);
        
        if(op == '+'){
            if(left + right != res){
                
                for(int j = base; j < 10; j++){
                    
                    int l = DecToBase(j, left);
                    int r = DecToBase(j, right);
                    int s = DecToBase(j, res);
                    
                    if(l + r == s){
                        // cout << left << ' ' << right << ' ' << res << '\n';
                        base = j;
                        return true;
                    }
                }
            }
        }else{
            if(left - right != res){
                
                for(int j = base; j < 10; j++){
                    
                    int l = DecToBase(j, left);
                    int r = DecToBase(j, right);
                    int s = DecToBase(j, res);
                    
                    if(l - r == s){
                        // cout << left << ' ' << right << ' ' << res << '\n';
                        base = j;
                        return true;
                    }
                }
            }
        }
    }
    
    return false;
}

bool CanOp(const string& left, const string& right, char op, int base){
    if(op == '+'){
        for(int i = 0 ; i < left.size() && i < right.size(); i++){
            if(left[left.size() -1 - i] + right[right.size() - 1 - i] - '0' - '0' >= base){
                // cout << base << ' ' << left[i] << ' ' << right[i];
                return false;
            }
                
        }
    }else{
        for(int i = 0 ; i < left.size() && i < right.size(); i++){
            if(left[left.size() -1 - i] - right[right.size() - 1 - i] < 0)
                return false;
        }
    }
    return true;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<string> notQuestions;
    vector<string> questions;
    for(int i = 0 ; i< expressions.size(); i++){
        expressions[i].back() == 'X' ? questions.push_back(expressions[i]) : notQuestions.push_back(expressions[i]);
    }
    
    int base = GetMaxBase(expressions);
    if(FindBase(notQuestions, base)){
        string str;
        for(int i = 0 ; i < questions.size(); i++){
            istringstream iss(questions[i]);
            iss >> str;
            int left = DecToBase(base, stoi(str));
            
            iss >> str;
            char op = str[0];
            
            iss >> str;
            int right = DecToBase(base, stoi(str));
            
            questions[i].pop_back();
            
            int res = op == '+' ? left + right : left - right;
            
            questions[i] += DecToBaseString(base, res);
        }
    }else{
        // 진법이 확정이 안났을 때
        string str;
        for(int i = 0 ; i < questions.size(); i++){
            istringstream iss(questions[i]);
            iss >> str;
            string left = str;
            
            iss >> str;
            char op = str[0];
            
            iss >> str;
            string right = str;
            questions[i].pop_back();
            if(CanOp(left, right, op, base)){
                if(op == '+'){
                    questions[i] += DecToBaseString(base, DecToBase(base,stoi(left))+DecToBase(base,stoi(right)));
                }else{
                    questions[i] += DecToBaseString(base, DecToBase(base,stoi(left))-DecToBase(base,stoi(right)));
                }
            }else{
                questions[i] += '?';
            }
        }
    }
    
    return questions;
}