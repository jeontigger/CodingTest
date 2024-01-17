#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void input(int& n, vector<pair<int, int>>& vec) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        vec.push_back(p);
    }
}

void solution(int n, vector<pair<int, int>> vec) {

    list<pair<int, int>> li;
    
    int maxValue = 0;

    for (int i = 0; i < vec.size(); i++) {
        li.push_back({ vec[i].first, vec[i].second + maxValue });

        for (auto iter = li.begin(); iter != li.end(); ) {
            (*iter).first--;
            if ((*iter).first == 0) {
                if (maxValue < iter->second)
                    maxValue = iter->second;
                iter = li.erase(iter);
                
            }
            else {
                ++iter;
            }
        }
    }
    cout << maxValue;


    return;
}

int main()
{
    int n;
    vector<pair<int, int>> vec;

    input(n, vec);
    solution(n, vec);

    return 0;
}