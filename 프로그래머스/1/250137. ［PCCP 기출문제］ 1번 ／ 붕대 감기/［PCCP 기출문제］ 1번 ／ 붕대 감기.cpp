#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int curTime = 1;
    
    int castingDuration = bandage[0];
    int healPerSec = bandage[1];
    int bonusHeal = bandage[2];
    int curHealth = health;
    
    for(int i = 0 ; i < attacks.size(); i++){
        int attackTime = attacks[i][0];
        int accTime = attackTime - curTime;
        int heal = accTime * healPerSec + (accTime / castingDuration) * bonusHeal;
        
        curHealth = min(health, heal + curHealth);
        curTime = attackTime+1;
        
        // cout << curTime << ' ' << curHealth << ' ' << accTime * healPerSec << ' ' << (accTime / castingDuration) * bonusHeal << '\n';
        
        int damage = attacks[i][1];
        curHealth -= damage;
        if(curHealth <= 0) return -1;
    }
    
    return curHealth;
}