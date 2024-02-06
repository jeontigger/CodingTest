#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int g_iCnt;
int g_iK;
void input(vector<bool>& brokens) {
    int n;
    cin >> g_iCnt >> g_iK >> n;

    brokens.resize(g_iCnt);
    for (size_t i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        brokens[idx-1] = true;
    }

}


void solution(vector<bool>& brokens) {

    int brokenCnt = 0;
    
    for (int i = 0; i < g_iK; i++) {
        if (brokens[i])
            brokenCnt++;
    }
    int minCnt = brokenCnt;
    for (int i = g_iK; i < brokens.size(); i++)
    {
        if (brokens[i])
            brokenCnt++;
        if (brokens[i - g_iK])
            brokenCnt--;
        minCnt = min(brokenCnt, minCnt);
    }
    cout << minCnt << endl;
}


int main()
{

    vector<bool> brokens;
    input(brokens);

    solution(brokens);

}
