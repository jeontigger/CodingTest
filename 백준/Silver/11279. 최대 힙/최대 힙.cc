#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

void input(vector<int>& inputs) {

    int n;
    cin >> n;

    inputs.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> inputs[i];
    }
}


void solution(vector<int>& inputs) {


    priority_queue<int> pq;
    for (size_t i = 0; i < inputs.size(); i++)
    {
        int num = inputs[i];
        if (num == 0) {
            if (pq.empty()) {
                //cout << 0 << endl;
                printf("0\n");
            }
            else {
                printf("%d\n", pq.top());
                //cout << pq.top() << endl;
                pq.pop();
            }
        }
        else {
            pq.push(num);
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> inputs;
    input(inputs);
    solution(inputs);
}
