#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int subinPos = 0;
int sisterPos = 0;

void input() {
    cin >> subinPos >> sisterPos;
}

struct fData {
    int cnt = 0;
    int pos = 0;

    fData(int _cnt, int _pos) { cnt = _cnt; pos = _pos; }
};

void solution() {

    constexpr int maxpos = 100001;
    int position[maxpos] = { 0, };


    list<fData> q;
    q.push_back({ 0, subinPos });

    int minCnt = maxpos;
    int resCnt = 0;

    while (!q.empty()) {
        auto data = q.front();
        q.pop_front();
        if (data.pos < 0 || data.pos >= maxpos)
            continue;

        if (data.cnt > minCnt)
            break;

        if (data.pos == sisterPos)
        {
            resCnt++;
            minCnt = data.cnt;
            continue;
        }

        if (position[data.pos] != 0 && position[data.pos] < data.cnt)
            continue;

        position[data.pos] = data.cnt;

        q.push_back({ data.cnt + 1, data.pos + 1 });
        q.push_back({ data.cnt + 1, data.pos - 1 });
        q.push_back({ data.cnt + 1, data.pos * 2 });

    }

    cout << minCnt << " " << resCnt << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solution();

}
