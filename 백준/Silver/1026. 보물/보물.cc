#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

void input(vector<int>& vec1, vector<int>& vec2) {
    int num;

    cin >> num;

    vec1.resize(num);
    vec2.resize(num);

    for (int i = 0; i < num; i++) {
        cin >> vec1[i];
    }

    for (int i = 0; i < num; i++) {
        cin >> vec2[i];
    }
}

void solution(vector<int> vec1, vector<int> vec2) {

    sort(vec1.begin(), vec1.end(), greater<int>());
    sort(vec2.begin(), vec2.end(), less<int>());

    int sum = 0;
    for (int i = 0; i < vec1.size(); i++) {
        sum += vec1[i] * vec2[i];
    }

    cout << sum << endl;

    return;
}

int main()
{
    vector<int> vec1;
    vector<int> vec2;

    input(vec1, vec2);
    solution(vec1, vec2);
}