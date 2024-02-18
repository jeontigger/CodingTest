#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int g_house;
int g_wifies;

void input(vector<int>& house) {
    cin >> g_house >> g_wifies;

    house.resize(g_house);
    for (size_t i = 0; i < g_house; i++)
    {
        cin >> house[i];
    }

    sort(house.begin(), house.end());

}

void solution(vector<int>& house) {

    int small = 0;
    int big = house.back();
    int testLen;
    int resLen = 0;
    while (small <= big) {
        testLen = (small + big) / 2;
        //cout << small << " " << big << " ";
        //cout << testLen << endl;

        int prev = house[0];
        int cnt = 1;
        for (int i = 1; i < house.size(); i++) {
            if (house[i] - prev >= testLen) {
                cnt++;
                prev = house[i];
            }
        }
            
        if (cnt >= g_wifies) {
            small = testLen + 1;
            resLen = testLen;
        }
        else {
            big = testLen - 1;
            //cout << cnt << " " << "smaller" << endl;
        }

    }
    cout << resLen << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> house;
    input(house);
    solution(house);

}
