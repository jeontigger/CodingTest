#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int left = wallpaper[0].size()-1, up = wallpaper.size()-1;
    int bottom = 0, right = 0;
    
    for(int i = 0 ; i<wallpaper.size();i++){
        for(int j = 0; j< wallpaper[0].size(); j++){
            char file = wallpaper[i][j];
            if(file == '#'){
                left = min(left, j);
                right = max(right, j + 1);
                up = min(up, i);
                bottom = max(bottom, i+1);
            }
        }
    }
    answer.push_back(up);
    answer.push_back(left);
    answer.push_back(bottom);
    answer.push_back(right);
    return answer;
}