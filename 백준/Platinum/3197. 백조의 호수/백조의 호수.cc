#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define endl "\n"
#define MAX 1500

using namespace std;

int R, C;
bool Find;
char MAP[MAX][MAX];
bool Visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 }; // Directions for moving right, left, down, up
int dy[] = { 1, -1, 0, 0 };

queue<pair<int, int>> Swan_Q, Swan_NQ, Q, NQ;
pair<int, int> Swan_Pos;

void Input() {
    Find = false;
    cin >> R >> C;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> MAP[i][j];
            
            if (MAP[i][j] != 'X') 
                Q.push(make_pair(i, j));
                
            if (MAP[i][j] == 'L') { // Find Swan position
                Swan_Pos.first = i;
                Swan_Pos.second = j;
            }
        }
    }
}

void Swan_BFS() {
    while (!Swan_Q.empty() && !Find) {
        int x = Swan_Q.front().first;
        int y = Swan_Q.front().second;
        Swan_Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
                if (!Visit[nx][ny]) {
                    if (MAP[nx][ny] == '.') {
                        Visit[nx][ny] = true;
                        Swan_Q.push(make_pair(nx, ny));
                    } 
                    else if (MAP[nx][ny] == 'L') {
                        Visit[nx][ny] = true;
                        Find = true;
                        break;
                    } 
                    else if (MAP[nx][ny] == 'X') {
                        Visit[nx][ny] = true;
                        Swan_NQ.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}

void Water_BFS() {
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
                if (MAP[nx][ny] == 'X') {
                    MAP[nx][ny] = '.'; // Melt ice
                    NQ.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void Solution() {
    int Day = 0;
    
    // Initialize the queue with the swan's starting position
    Swan_Q.push(make_pair(Swan_Pos.first, Swan_Pos.second));
    Visit[Swan_Pos.first][Swan_Pos.second] = true;

    while (!Find) {
        Swan_BFS(); // Move the swan

        if (!Find) {
            Water_BFS(); // Melt the ice
            Q = NQ;      // Update the water queue
            Swan_Q = Swan_NQ; // Update the swan queue

            while (!NQ.empty()) NQ.pop();  // Clear NQ
            while (!Swan_NQ.empty()) Swan_NQ.pop(); // Clear Swan_NQ
            
            Day++; // Increase the day counter
        }
    }
    
    cout << Day << endl; // Output the result
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // freopen("Input.txt", "r", stdin); // Uncomment for file input
    Solve();
    
    return 0;
}