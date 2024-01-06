#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int strToTime(string str) {
    string h = str.substr(0, 2);
    string m = str.substr(3);


    return stoi(h) * 60 + stoi(m);
}

string timeToStr(int time) {
    string answer = "";
    int h = time / 60;
    int m = time % 60;
    string hour = "";
    if (h / 10 == 0) {
        hour += "0";
    }
    hour += to_string(h);

    string min = "";
    if (m / 10 == 0) {
        min += "0";
    }
    min += to_string(m);
    answer = hour + ":" + min;
    return answer;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    sort(timetable.begin(), timetable.end());

    int crueIdx = 0;
    int startHour = 9;
    int startMin = 0;
    int boardCnt = 0;

    int coneTime = 0;
    for (int i = 0; i < n; i++) {
        int goTime = startHour * 60 + startMin + t * i;

        boardCnt = 0;
        for (int j = 0; j < m && crueIdx < timetable.size(); j++, crueIdx++) {
            int cruetime = strToTime(timetable[crueIdx]);

            if (cruetime <= goTime) {
                boardCnt++;
            }
            else {
                break;
            }
        }

        if (boardCnt < m) {
            coneTime = goTime;
        }
        else {
            coneTime = strToTime(timetable[crueIdx - 1]) - 1;
            cout << "???" << endl;
        }
    }

    return timeToStr(coneTime);
}