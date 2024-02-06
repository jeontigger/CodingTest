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

void input(vector<int>& vec) {
    int n;
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
}


void solution(vector<int>& cases) {
    constexpr int arrNum = 303;
    int stars[arrNum] = {};
    stars[0] = 0;

    int Ws[arrNum] = {};
    Ws[0] = 0;
    for (int i = 1; i < arrNum; i++)
    {
        stars[i] = stars[i - 1] + i;
    }

    for (int i = 1; i < arrNum - 1; i++)
    {
        Ws[i] = Ws[i-1] + i * stars[i+1];
    }

    for (size_t i = 0; i < cases.size(); i++)
    {
        int cas = cases[i];
        cout << Ws[cas] << endl;
    }

    return;
}


int main()
{
    vector<int> cases;
    input(cases);

    solution(cases);

}
