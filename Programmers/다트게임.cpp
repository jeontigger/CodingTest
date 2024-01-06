#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    int left = 0;
    int cnt = 0;
    vector<int> score;
    for (int i = 0; i < dartResult.length(); i++) {
        char c = dartResult[i];
        if (c == 'S' || c == 'D' || c == 'T') {
            string sub = dartResult.substr(left, i - left);
            score.push_back(stoi(sub));
            switch (c) {
            case 'S':
                score[cnt] = score[cnt];
                break;
            case 'D':
                score[cnt] = score[cnt] * score[cnt];
                break;
            case 'T':
                score[cnt] = score[cnt] * score[cnt] * score[cnt];
                break;
            }
            cnt++;
            left = i + 1;
        }

        if (c == '*' || c == '#') {
            switch (c) {
            case '*':
            {
                score[cnt - 1] *= 2;
                if (cnt != 1) {
                    score[cnt - 2] *= 2;
                }
                break;
            }
            case '#':
            {
                score[cnt - 1] *= -1;
                break;
            }
            }
            left = i + 1;
        }
        // for(int i: score){
        //     cout << i << " ";
        // }
        // cout << endl;
    }

    for (int i : score) {
        answer += i;
    }
    return answer;
}