#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int g_weight;
int g_length;

void input(vector<int>& trucks) {
    int n;
    cin >> n >> g_length >> g_weight;

    trucks.resize(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> trucks[i];
    }

}

void solution(vector<int>& trucks) {
    int curWeight = 0;
    int curTime = 0;

    vector<int> bridge;
    bridge.resize(g_length);

    for (size_t i = 0; i < trucks.size(); )
    {
        if (bridge[0] != 0) {
            curWeight -= bridge[0];
        }

        for (size_t j = 0; j < bridge.size() - 1; j++)
        {
            bridge[j] = bridge[j + 1];
        }

        if (curWeight + trucks[i] <= g_weight) {
            bridge[bridge.size() - 1] = trucks[i];
            curWeight += trucks[i];
            i++;
        }
        else {
            bridge[bridge.size() - 1] = 0;
        }

        curTime++;
    }

    cout << curTime + g_length << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> trucks;
    input(trucks);
    solution(trucks);
    
}
