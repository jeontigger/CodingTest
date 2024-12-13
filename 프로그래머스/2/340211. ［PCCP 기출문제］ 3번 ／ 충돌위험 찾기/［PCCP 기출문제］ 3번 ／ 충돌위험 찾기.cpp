#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Pos{
    int row = 0;
    int col = 0;
    int idx = 0;
    int targetIdx = 1;
};

// 첫 시작 지점을 등록
void Init(vector<vector<int>>& maps, const vector<vector<int>>& points, const vector<vector<int>>& routes, queue<Pos>& robotPos){
    for(int i = 0 ; i < routes.size(); i++){
        int startIdx = routes[i][0] - 1;
        auto pos = points[startIdx];
        maps[pos[0]][pos[1]]++;
        robotPos.push({pos[0], pos[1], i});
    }
}

int CollisionCnt(vector<vector<int>>& maps){
    int res = 0;
    
    for(int i = 0 ; i < maps.size(); i++){
        for(int j = 0 ; j < maps[0].size(); j++){
            if(maps[i][j] >1){
                res ++;
            }
        }
    }
    // cout << res << '\n';
    
    return res;
}

void PrintQ(queue<Pos> q){
    while(!q.empty()){
        Pos pos = q.front();
        q.pop();
        cout << pos.row << ' ' << pos.col << ' ' << pos.idx << ' ' << pos.targetIdx << '\n';
    }
    cout << '\n';
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    vector<vector<int>> maps(101, vector<int>(101));
    queue<Pos> q;
    
    // 현재 지점, 가야할 지점
    Init(maps, points, routes, q);
    // // PrintQ(q);
    
    answer += CollisionCnt(maps);
    
    int cnt = 0;
    while(!q.empty()){
        int size = q.size();
        cnt++;
        // cout << "Cnt : "<< cnt << '\n';
        while(size--){
            Pos pos = q.front();
            q.pop();
            maps[pos.row][pos.col]--;
            

            
            // 진행중
            auto targetPos = points[routes[pos.idx][pos.targetIdx]-1];
            if(pos.row == targetPos[0] && pos.col == targetPos[1]){
                pos.targetIdx++;
            }
            // 완전 도착일 때 삭제
            if(pos.targetIdx >= routes[pos.idx].size()) continue;
            
            targetPos = points[routes[pos.idx][pos.targetIdx]-1];
            if(pos.row != targetPos[0]){
                // row가 다를 때
                targetPos[0] > pos.row ? pos.row++ : pos.row--;
            }else if(pos.col != targetPos[1]){
                // col이 다를 때
                targetPos[1] > pos.col ? pos.col++ : pos.col--;
            }
            q.push(pos);
            maps[pos.row][pos.col]++;
        }
        // PrintQ(q);
        
        // 충돌 개수 검사
        answer+= CollisionCnt(maps);
    }
    
    return answer;
}