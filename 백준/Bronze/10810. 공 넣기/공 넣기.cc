#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int g_row;
int g_col;
int g_nrow[4] = { 0, 1, 0, -1 };
int g_ncol[4] = { 1, 0, -1, 0 };

int g_cnt = 0;
int g_target = 0;

vector<int> g_buckets;

struct fData {
    int start;
    int end;
    int num;
};
void input(vector<fData>& balls) {
    int n;
    cin >> n >> g_cnt;
    g_buckets.resize(n);
    balls.resize(g_cnt);

    for (size_t i = 0; i < balls.size(); i++)
    {
        cin >> balls[i].start >> balls[i].end >> balls[i].num;
    }

    for (size_t i = 0; i < balls.size(); i++)
    {
        balls[i].start -= 1;
        balls[i].end -= 1;
    }
}

void solution(vector<fData>& balls) {
    
    for (size_t i = 0; i < balls.size(); i++)
    {
        auto ball = balls[i];
        for (size_t j = ball.start; j <= ball.end; j++)
        {
            g_buckets[j] = ball.num;
        }
    }
    for (size_t i = 0; i < g_buckets.size(); i++)
    {
        cout << g_buckets[i] << " ";
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<fData> balls;
    input(balls);
    solution(balls);

}