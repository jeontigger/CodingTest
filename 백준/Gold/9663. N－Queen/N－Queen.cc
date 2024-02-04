#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

vector<vector<bool>> g_vec;
int g_cnt = 0;

void input() {
    int n;
    cin >> n;

    g_vec.resize(n);
    for (vector<bool>& v : g_vec) {
        v.resize(n);
    }
}

void Queen(vector<int>& vec, int cnt) {
    if (cnt == vec.size()) {
        g_cnt++;
        return;
    }
   
    for (int i = 0; i < vec.size(); i++)
    {
        bool cont = false;
        for (int j = 0; j < cnt; j++)
        {
            if (vec[j] == i) {
                cont = true;
                break;
            }
        }

        if (cont)
            continue;

        for (int j = 0; j < cnt; j++)
        {
            if (abs(vec[j] - i) == abs(cnt - j)) {
                cont = true;
                break;
            }
        }

        if (cont)
            continue;

        vec[cnt] = i;
        Queen(vec, cnt + 1);
    }

}

void solution() {
    int cnt = 0;

    vector<int> vec;
    vec.resize(g_vec.size());

    Queen(vec, 0);

    cout << g_cnt << endl;
    return;
}


int main()
{

    input();

    solution();

}