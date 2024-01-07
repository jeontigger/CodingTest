#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

struct startSmall {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first != p2.first ? p1.first > p2.first : p1.second < p2.second;
    }
};

struct endBig {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

void printList(list<pair<int, int>>& li) {
    for (auto pair = li.begin(); pair != li.end(); ++pair) {
        cout << (*pair).first << " " << (*pair).second << endl;
    }
}

int solution(vector<string> lines) {
    int answer = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, startSmall> pq;

    for (int i = 0; i < lines.size(); i++) {
        string str = lines[i].substr(11, 12);

        // cout << str << " ";
        int hour = stoi(str.substr(0, 2));
        int min = stoi(str.substr(3, 2));
        int sec = stoi(str.substr(6, 2));
        int msec = stoi(str.substr(9, 3));

        string str2 = lines[i].substr(23);
        str2 = str2.substr(0, str2.length() - 1);
        int duration = stof(str2) * 1000;

        // cout << hour << " " << min << " " << sec << " " << msec << endl;

        int endTime = msec + sec * 1000 + min * 1000 * 60 + hour * 1000 * 60 * 60;
        int startTime = endTime - duration;

        pq.push({ startTime, endTime });
    }

    // while(!pq.empty()){
    //     cout << pq.top().first << " " << pq.top().second << endl;
    //     pq.pop();
    // }

    priority_queue<pair<int, int>, vector<pair<int, int>>, endBig> pq2;

    while (!pq.empty()) {
        auto p = pq.top();
        pq2.push(p);
        pq.pop();

        while (!pq2.empty()) {
            auto queuepair = pq2.top();
            if (queuepair.second <= p.first - 999) {
                pq2.pop();
            }
            else {
                break;
            }
        }

        // printList(q);
        // cout << endl;
        answer = std::max(answer, (int)pq2.size());
    }

    // while(!pq2.empty()){
    //     cout << pq2.top().first << " " << pq2.top().second << endl;
    //     pq2.pop();
    // }


    return answer;
}