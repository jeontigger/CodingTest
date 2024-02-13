#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int g_cnt = 0;

void input(vector<vector<int>> &vec) {
    int n;
    cin >> n;

    vec.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        vec[i].resize(n);
        for (size_t j = 0; j < n; j++)
        {
            cin >> vec[i][j];
        }
    }
}

// right, cross, down
enum Dir {
    Right,
    Cross,
    Down,
    END
};
int g_dirRow[3] = { 0, 1, 1 };
int g_dirCol[3] = { 1, 1, 0 };

void print(vector<vector<int>>& maps, pair<int, int> pos) {
    cout << pos.first << " " << pos.second << endl;

    for (auto v : maps) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

}

void dfs(vector<vector<int>>& maps, pair<int, int> pos, int dir) {
    

    int crow = pos.first + g_dirRow[dir];
    int ccol = pos.second + g_dirCol[dir];

    if (crow >= maps.size() || ccol >= maps.size() || maps[crow][ccol] == 1) return;

    if ((dir == (int)Cross) && ((maps[crow - 1][ccol] == 1) || (maps[crow][ccol - 1] == 1)))
    {
        return;
    }

    if (crow == maps.size() - 1 && ccol == maps.size() - 1) {
        g_cnt++;
        return;
    }

    //print(maps, { crow, ccol });
    maps[crow][ccol] = 1;


    for (size_t i = 0; i < END; i++)
    {
        if (dir == Right && i == Down)
            continue;
        if (dir == Down && i == Right)
            continue;
        
        dfs(maps, { crow , ccol }, i);
    }
    maps[crow][ccol] = 0;

}

void solution(vector<vector<int>>& maps) {

    dfs(maps, { 0, 0 }, 0);

    cout << g_cnt << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> maps;
    input(maps);
    solution(maps);

}
