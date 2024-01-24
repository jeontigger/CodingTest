#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

void input(vector<vector<pair<int, int>>>& data) {
    int n;
    cin >> n;

    data.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        data[i].resize(m);
        for (size_t j = 0; j < m; j++)
        {
            cin >> data[i][j].first >> data[i][j].second;
        }
    }
}

void solution(vector<vector<pair<int, int>>>& data) {

    for (vector<pair<int, int>>& v : data) {
        sort(v.begin(), v.end());

        int minValue = v[0].second;

        int cnt = 0;
        for (auto& p : v) {
            if (minValue < p.second) {
                cnt++;
            }
            else {
                minValue = p.second;
            }
        }
        cout << v.size() - cnt << endl;
        
    }
    
}

int main()
{
    vector<vector<pair<int, int>>> data;

    input(data);

    solution(data);
}
