#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

void input(int& m, vector<int>& vec) {
    int n;
    cin >> n;
    cin >> m;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
}

void GetNextIdx(int& idx, const vector<int>& vec) {
    int i = idx + 1;
    for (; i < vec.size() - 1; i++) {
        if (vec[i] != vec[i + 1]) {
            break;
        }
    }
    idx = i;
    return;
}

void solution(int targetlen, vector<int> vec) {

    sort(vec.begin(), vec.end(), greater<int>());

    long long maxValue = vec[0];

    for (int i = 0; i < vec.size() - 1; i++) {
        vec[i] = vec[i] - vec[i + 1];
    }

    long long sum = 0;
    long long prevSum = sum;
    long long cnt = 0;
    for (int i = 0; i < vec.size(); i++) {
        prevSum = sum;
        for (int j = 0; j < vec[i]; j++) {
            sum = (i + 1) * (j + 1)+ prevSum;
            cnt++;
            if (targetlen <= sum) {
                cout << maxValue - cnt << endl;
                return;
            }
        }
        //cout << maxValue - cnt << " " << sum << endl;
    }
    return;
}

int main()
{
    int m;
    vector<int> vec;

    input(m, vec);
    solution(m, vec);
}