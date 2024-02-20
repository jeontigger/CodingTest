#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int g_row;
int g_col;

int g_cnt;
int g_len;
int g_interval;
#define songinterval 5

void input() {
    cin >> g_cnt >> g_len >> g_interval;
}

void solution() {

    int maxLen = g_cnt * (g_len + songinterval) - songinterval;

    int sum = 0;
    while (sum <= maxLen) {
        sum += g_interval;
        if (sum % (g_len + songinterval) >= g_len)
            break;
    }

    cout << sum << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();

}
