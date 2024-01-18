
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

void input(vector<pair<int, int>>& vec) {
    int num;

    cin >> num;
    vec.resize(num);
    for (int i = 0; i < num; i++) {
        cin >> vec[i].first >> vec[i].second;
    }
}

void solution(vector<pair<int, int>> vec) {

    sort(vec.begin(), vec.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
        if (p1.first != p2.first) {
            return p1.first < p2.first;
        }
        else {
            return p1.second < p2.second;
        }
        });
    vector<pair<int, int>> container;
    container.push_back(vec[0]);
    for (int i = 1; i < vec.size(); i++) {
        auto p =  vec[i];
        int start = container.back().first;
        int end = container.back().second;

        int curStart = p.first;
        if (end <= curStart) {
            container.push_back(p);
        }
        else {
            int curEnd = p.second;
            if (curEnd <= end) {
                container.pop_back();
                container.push_back(p);
            }
        }
    }

    cout << container.size() << endl;
  
    return;
}

int main()
{
    vector<pair<int, int>> vec;

    input(vec);
    solution(vec);

}
