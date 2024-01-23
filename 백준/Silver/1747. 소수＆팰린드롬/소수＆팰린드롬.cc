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

void solution(int num) {

    // num 이상인 수 && 소수 && 팰린드롬

    // 소수 판별
        // 2부터 sqrt(n)까지
    
    if(num <= 1){
        num = 2;
    }

    while (true) {

        bool isPrime = true;
        for (size_t i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        // 소수라면 팰린드롬 판별
        if (isPrime) {
            string str = to_string(num);

            size_t strLen = str.length();

            bool isPalindrome = true;
            for (size_t j = 0; j <= strLen/2; j++)
            {
                if (str[j] != str[strLen - 1 - j]) {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome) {
                cout << num << endl;
                break;
            }

        }

        num++;
        if (num >= 100000000)
        {
            cout << "OVER" << endl;
            break;
        }
    }

}

int main()
{
    int num;

    input(num);
    solution(num);
}
