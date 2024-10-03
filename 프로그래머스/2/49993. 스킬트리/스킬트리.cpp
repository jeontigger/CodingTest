#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    int idx = 0;
    for(int i =0; i < skill_trees.size();i++){
        string curSkill = skill_trees[i];
        idx = 0;
        for(int j = 0 ; j < curSkill.size();j++){
            if(curSkill[j] == skill[idx]){
                idx++;
                // cout << "idx++" << endl;
                continue;
            }
            
            // cout << curSkill[j] << " " << skill[idx] << endl;
            
            bool isBreak = false;
            for(int k = idx; k < skill.size();k++){
                if(skill[k] == curSkill[j]){
                    answer--;
                    // cout << idx << " " << curSkill[j] << endl;
                    isBreak = true;
                    break;
                }
            }
            if(isBreak)
                break;
            
        }
        cout << endl;
        answer++;
    }
    
    return answer;
}