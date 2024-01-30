#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

string targetChannel;

void input(vector<vector<bool>>& vec) {
    int n;
    int num;

    cin >> n >> num;

    vec.resize(n);
    for (size_t i = 0; i < vec.size(); i++)
    {
        vec[i].resize(n);
    }

    for (size_t i = 0; i < num; i++)
    {
        int one, two;
        cin >> one >> two;
        vec[one - 1][two - 1] = true;
        vec[two - 1][one - 1] = true;
    }


}

void solution(vector<vector<bool>>& graph) {
    list<int> q;

    vector<bool> check;
    check.resize(graph.size());

    q.push_back(0);
    check[0] = true;

    while (!q.empty()) {
        auto computer = q.front();
        q.pop_front();

        for (size_t i = 0; i < graph[computer].size(); i++)
        {
            if (!check[i] && graph[computer][i]) {
                q.push_back(i);
                check[i] = true;
            }
        }
    }

    int res = -1;
    for (bool b : check) {
        if (b) {
            res++;
        }
    }

    cout << res << endl;
}


int main()
{
    vector<vector<bool>> graph;

    input(graph);

    solution(graph);

}
