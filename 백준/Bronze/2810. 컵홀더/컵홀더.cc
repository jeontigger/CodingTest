#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

void input(string& str) {
    int n;
    cin >> n;
    cin >> str;
}


void solution(string& str) {

    int scnt = 0;
    int lcnt = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == 'S') {
            scnt++;
        }
    }
    lcnt = str.length() - scnt;
    lcnt /= 2;


    cout << min((int)str.length(), scnt + lcnt + 1) << endl;
}


int main()
{

    string str;
    input(str);

    solution(str);

}
