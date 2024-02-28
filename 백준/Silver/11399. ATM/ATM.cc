#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;
int g_row;
int g_col;
int g_nrow[4] = { 0, 1, 0, -1 };
int g_ncol[4] = { 1, 0, -1, 0 };

int g_cnt = 0;
int g_target = 0;

void input() {
    
}

void solution() {
    
    int n;
    cin >> n;
    vector <int> vec;
    vec.resize(n);
    for (size_t i = 0; i < vec.size(); i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        vec[i + 1] += vec[i];
    }

    int sum = 0;
    for (size_t i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
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
