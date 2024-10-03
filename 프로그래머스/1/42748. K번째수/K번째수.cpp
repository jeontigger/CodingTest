#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++){
        vector<int> command = commands[i];
        vector<int> sorted(array.begin() + command[0] - 1, array.begin() + command[1]);
        sort(sorted.begin(), sorted.end());
        // for(auto i : sorted){
        //     cout << i << " " ;
        // }
        answer.push_back(sorted[command[2]-1]);
        
    }
    return answer;
}