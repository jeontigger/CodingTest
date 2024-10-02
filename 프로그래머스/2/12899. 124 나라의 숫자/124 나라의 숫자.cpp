#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n > 0){
        int mod = (n)%3;
        if(mod == 1){
            answer = "1" + answer;
        }else if (mod == 2){
            answer = "2" + answer;
        }else{
            answer = "4" + answer;
        }
        n--;
        n /= 3;
    }
    return answer;
}