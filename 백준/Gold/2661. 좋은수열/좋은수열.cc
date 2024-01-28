#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int targetNum;
bool allReturn;
void input() {

    cin >> targetNum;

}
bool IsGood(const string& str) {

    for (int i = 1; i <= str.length() / 2; ++i)
    {
        string str1 = str.substr(str.length() - (i * 2), i);
        string str2 = str.substr(str.length() - i, i);

        if (str1 == str2)
        {
            return false;
        }
    }

    return true;
}

void solution(string str) {
    if (!IsGood(str)) {
        return;
    }

    if (allReturn) {
        return;
    }

    if (str.length() == targetNum) {
        cout << str << endl;
        allReturn = true;
        return;
    }

    solution(str + "1");
    solution(str + "2");
    solution(str + "3");
    
}

int main()
{
    input();

    allReturn = false;
    solution("");

    return 0 ;
}
