#pragma once
// CondingTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

void input(int& num) {
    cin >> num;
}

bool isPalin(int num) {
    string str = to_string(num);
    size_t strLen = str.length();

    for (size_t j = 0; j <= strLen / 2; j++)
    {
        if (str[j] != str[strLen - 1 - j]) {
            return false;
        }
    }

    return true;
}

bool isPrime(int num) {

    for (size_t i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void solution(int num) {

    // num 이상인 수 && 소수 && 팰린드롬

    // 소수 판별
        // 2부터 sqrt(n)까지
    if (num <= 1) {
        num = 2;
    }
    if (num == 2) {
    cout << 2;
    return;
}

    if (num % 2 == 0) {
        num++;
    }

    while (true) {

        if (isPalin(num) && isPrime(num)) {
            cout << num << endl;
            break;
        }
       
        num+=2;
        if (num >= 100000000)
        {
            cout << "OVER" << endl;
            break;
        }
    }

}

int main()
{
    vector<vector<int>> grid;

    int num;
    input(num);
    solution(num);

}
