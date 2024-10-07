#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;

    vector<long long> arr(2001,0);

    for(const auto v : weights)
    {
        arr[v]++;
    }

    for(int i = 100; i <= 1000; ++i)
    {
        if(arr[i] == 0)
        {
            continue;
        }

        answer += arr[i]*(arr[i]-1) / 2;

        answer += arr[i] * arr[2 * i];

        if((i * 3) % 2 == 0)
        {
            answer += arr[i] * arr[i * 3 / 2];
        }

        if((i * 4) % 3 == 0)
        {
            answer += arr[i] * arr[i * 4 / 3];
        }   
    }

    return answer;
}