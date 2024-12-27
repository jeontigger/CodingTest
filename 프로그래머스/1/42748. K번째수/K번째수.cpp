#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0 ; i < commands.size(); i++){
        int left = commands[i][0]-1;
        int right = commands[i][1];
        int k = commands[i][2]-1;
        vector<int>v (array.begin() + left, array.begin() + right);
        sort(v.begin(), v.end());
        answer.push_back(v[k]);
    }
    return answer;
}