#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int targetNum;
int res = 2147483647;
vector<vector<int>> g_homes;
vector<int>dp;

void input(vector<vector<int>>& vec) {
    int n;
    cin >> n;
    targetNum = n;

    vec.resize(n);
    dp.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        int r, g, b;
        cin >> r >> g >> b;
        vec[i].resize(3);
        vec[i][0] = r;
        vec[i][1] = g;
        vec[i][2] = b;
    }

}


void solution(vector<vector<int>>& homes) {
    g_homes = homes;

    int curColor = 0;

    for (size_t i = 1; i < homes.size(); i++)
    {
        vector<int> prevHome = homes[i-1];
        int minR = min(prevHome[1], prevHome[2]);
        int minG = min(prevHome[0], prevHome[2]);
        int minB = min(prevHome[0], prevHome[1]);

        homes[i][0] += minR;
        homes[i][1] += minG;
        homes[i][2] += minB;
    }

    cout << *min_element(homes.back().begin(), homes.back().end());
}


int main()
{
    vector<vector<int>> homes;

    input(homes);

    solution(homes);

}
