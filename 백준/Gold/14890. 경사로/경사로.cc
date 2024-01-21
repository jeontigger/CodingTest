#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

void input(int& clampLen, vector<vector<int>> &vec) {
    int n;
    cin >> n >> clampLen;

    vec.resize(n);
    for (int i = 0; i < n; i++) {
        vec[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }
}
void leftCheck(int clampLen, const vector<vector<int>>& vec, vector<vector<int>>& vecCheck, int& disableCnt) {
    int n = vec.size();
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - 1; j++) {
            int cur = vec[i][j];
            int next = vec[i][j + 1];
            int prevDisableCnt = disableCnt;
            if (cur - 1 > next) {
                disableCnt++;
                break;
            }
            if (cur - 1 == next) {
                int cnt = 0;
                for (int k = j + 1; k < vec.size(); k++) {
                    int chk = vec[i][k];
                    if (chk != next)
                        break;

                    cnt++;

                    if (cnt == clampLen)
                        break;
                }
                for (int k = 0; k < clampLen; k++) {
                    if (cnt == clampLen) {
                        if (vecCheck[i][j + 1 + k] != 0)
                        {
                            disableCnt++; break;
                        }
                        vecCheck[i][j + 1 + k]++;
                    }
                    else if (cnt < clampLen) {
                        disableCnt++;
                        break;
                    }
                }
                if (disableCnt != prevDisableCnt)
                {
                    break;
                }
            }

            cur = vec[i][n - 1 - j];
            next = vec[i][n - 2 - j];
            if (cur - 1 > next) {
                disableCnt++;
                break;
            }
            if (cur - 1 == next) {
                int cnt = 0;
                for (int k = j + 1; k < n; k++) {
                    int chk = vec[i][n - 1 - k];
                    if (chk != next)
                        break;

                    cnt++;

                    if (cnt == clampLen)
                        break;
                }
                for (int k = 0; k < clampLen; k++) {
                    if (cnt == clampLen) {
                        if (vecCheck[i][n - 2 - j - k] != 0)
                        {
                            disableCnt++; break;
                        }
                        vecCheck[i][n - 2 - j - k]++;
                    }
                    else if (cnt < clampLen) {
                        disableCnt++;
                        break;
                    }
                }
                if (disableCnt != prevDisableCnt)
                {
                    break;
                }
            }

        }
    }
}void upCheck(int clampLen, const vector<vector<int>>& vec, vector<vector<int>>& vecCheck, int& disableCnt) {
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            int cur = vec[j][i];
            int next = vec[j+1][i];
            int prevDisableCnt = disableCnt;
            if (cur - 1 > next) {
                disableCnt++;
                break;
            }
            if (cur - 1 == next) {
                int cnt = 0;
                for (int k = j + 1; k < n; k++) {
                    int chk = vec[k][i];
                    if (chk != next)
                        break;

                    cnt++;

                    if (cnt == clampLen)
                        break;
                }
                for (int k = 0; k < clampLen; k++) {
                    if (cnt == clampLen) {
                        if (vecCheck[j + 1 + k][i] != 0)
                        {
                            disableCnt++; break;
                        }
                        vecCheck[j + 1 + k][i]++;
                    }
                    else if (cnt < clampLen) {
                        disableCnt++;
                        break;
                    }
                }

                if (disableCnt != prevDisableCnt)
                    break;
            }


            cur = vec[n - 1 - j][i];
            next = vec[n - 2 - j][i];
            if (cur - 1 > next) {
                disableCnt++;
                break;
            }
            if (cur - 1 == next) {
                int cnt = 0;
                for (int k = j + 1; k < n; k++) {
                    int chk = vec[n - 1 - k][i];
                    if (chk != next)
                        break;

                    cnt++;

                    if (cnt == clampLen)
                        break;
                }
                for (int k = 0; k < clampLen; k++) {
                    if (cnt == clampLen) {
                        if (vecCheck[n - 2 - j - k][i] != 0)
                        {
                            disableCnt++; break;
                        }
                        vecCheck[n - 2 - j - k][i]++;
                    }
                    else if (cnt < clampLen) {
                        disableCnt++;
                        break;
                    }
                }

                if (disableCnt != prevDisableCnt)
                    break;
            }
        }
    }
}
void solution(int clampLen, vector<vector<int>>& vec) {

    vector<vector<int>> vecCheck;
    vecCheck.resize(vec.size());
    for (int i = 0; i < vec.size(); i++) {
        vecCheck[i].resize(vec.size());
    }

    int disableCnt = 0;
    // left -> right
    leftCheck(clampLen, vec, vecCheck, disableCnt);

    for (vector<int>& v : vecCheck) {
        for (int& i : v) {
            i = 0;
        }
    }

    // right->left
    upCheck(clampLen, vec, vecCheck, disableCnt);

    /*for (vector<int> v : vecCheck) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }*/
    cout << vec.size() * 2 - disableCnt << endl;
}

int main()
{
    int clampLen;
    vector<vector<int>> vec;

    input(clampLen, vec);

    solution(clampLen, vec);
}