#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

void input(int& subin, int& sister) {
    cin >> subin >> sister;
}

bool checked[200000];

void solution(int subin, int sister) {

    list<pair<int, int>> q;

    q.push_back({ subin, 0 });

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop_front();

        int iSubin = p.first;
        int cnt = p.second;

        if (checked[iSubin])
            continue;
        
        checked[iSubin] = true;
        if (iSubin == sister) {
            cout << cnt << endl;
            break;
        }

        if (iSubin - 1 >= 0)
            q.push_back({ iSubin - 1 , cnt + 1 });
        if (iSubin + 1 <= 200000) 
            q.push_back({ iSubin + 1 ,  cnt + 1 });
        if (iSubin * 2 <= 200000) 
            q.push_back({ iSubin * 2, cnt + 1 });
    }
    
}

int main()
{
    int subin, sister;

    input(subin, sister);

    solution(subin, sister);  
}
