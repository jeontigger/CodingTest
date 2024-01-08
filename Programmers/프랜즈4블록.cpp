#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> g_board;
char BlinkChar = '#';

char GetNotBlink(int irow, int icol) {
    if (irow < 0 || g_board.size() <= irow)
        return BlinkChar;
    if (icol < 0 || g_board[0].length() <= icol)
        return BlinkChar;
    char cur = g_board[irow][icol];
    return cur;
}

void SetBlink(int irow, int icol, vector<string>& board) {
    board[irow][icol] = BlinkChar;
}

int CountingBlink(const vector<string>& board) {
    int res = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].length(); j++) {
            char c = board[i][j];

            if (c == BlinkChar)
                res++;
        }
    }

    return res;
}
void DownBoard(vector<string>& board) {
    for (int i = 0; i < board[i].length(); i++) {
        for (int j = board.size() - 1; j > 0; j--) {
            char c = board[j][i];
            if (c == BlinkChar) {
                int upIdx = -1;
                char next;

                while (true) {
                    if (j + upIdx < 0) {
                        next = BlinkChar;
                        break;
                    }
                    next = board[j + upIdx][i];
                    if (next != BlinkChar) {
                        break;
                    }
                    upIdx--;
                }

                if (next != BlinkChar) {
                    board[j][i] = next;
                    board[j + upIdx][i] = BlinkChar;
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;


    int prev = -1;
    // for(string str : board)
    //     cout << str << endl;
    // cout << endl;

    while (prev != answer) {
        prev = answer;
        g_board = board;
        for (int i = m - 1; i > 0; i--) {
            for (int j = 0; j < n - 1; j++) {
                // ¹Ù´ÚºÎÅÍ
                char cur = GetNotBlink(i, j);

                if (cur < 'A' || 'Z' < cur) {
                    continue;
                }

                char right = GetNotBlink(i, j + 1);

                char up = GetNotBlink(i - 1, j);

                char upright = GetNotBlink(i - 1, j + 1);

                // cout << i << " " << j << " " << cur << " " << right << " " << up << " " << upright << endl;

                if (cur == right && right == up && up == upright) {
                    SetBlink(i, j, board);
                    SetBlink(i, j + 1, board);
                    SetBlink(i - 1, j, board);
                    SetBlink(i - 1, j + 1, board);
                }
            }
        }

        //         for(string str : board)
        //             cout << str << endl;
        //         cout << endl;

        DownBoard(board);

        // for(string str : board)
        //     cout << str << endl;
        // cout << endl;
        // cout << "=========================" << endl;

        answer = CountingBlink(board);
    }
    return answer;
}