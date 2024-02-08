#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int g_maxWeight;

struct fData {
    float weight;
    float value;
};


void input(vector<fData>& vec) {
    int n;
    cin >> n >> g_maxWeight;

    vec.resize(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> vec[i].weight >> vec[i].value;
    }
}

void solution(vector<fData>& vec) {
    vector<int> dp;
    vector<int> prevDP;
    dp.resize(g_maxWeight + 1);
    prevDP.resize(g_maxWeight + 1);
    
    for (size_t i = 0; i < vec.size(); i++)
    {
        auto data = vec[i];
        int value = data.value;
        int weight = data.weight;
        if (weight > g_maxWeight)
            continue;

        prevDP = dp;
        for (size_t j = 0; j < dp.size() - weight; j++)
        {
            dp[weight + j] = max(prevDP[weight + j], value + prevDP[j]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<fData> vec;
    input(vec);
    solution(vec);

}
