#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <locale>
#include <list>


using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].size(); j++) {
            if ('A' <= cities[i][j] && cities[i][j] <= 'Z')
                cities[i][j] += 'a' - 'A';
        }
    }
    list<string> cache;
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        auto iter = find(cache.begin(), cache.end(), city);
        if (iter == cache.end()) {
            answer += 5;
            cache.push_back(city);
        }
        else {
            cache.erase(iter);
            answer += 1;
            cache.push_back(city);
        }

        if (cache.size() > cacheSize) {
            cache.pop_front();
        }

    }

    return answer;
}