#include <string>
#include <vector>

using namespace std;

int g_nrow[] = {0, 1, 0, -1};
int g_ncol[] = {1, 0, -1, 0};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    string color = board[h][w];
    int N = board.size();
    int M = board[0].size();
    for(int i = 0 ; i < 4; i++){
        int nrow = h + g_nrow[i];
        int ncol = w + g_ncol[i];
        if(0 <= nrow && nrow < N && 0 <= ncol &&  ncol < M){
            if(board[nrow][ncol] == color)
                answer++;
        }
    }
    
    return answer;
}