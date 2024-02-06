#include <cstdio>
#include <cstdlib>

using namespace std;
int col, row;
int newCol, newRow;
int dirCol[4] = {1, 0, -1, 0};
int dirRow[4] = {0, 1, 0, -1};

void printBatchu(int** bat) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d", bat[i][j]);
        }
        printf("\n");
    }
}
void bfs(int** bat, int curCol, int curRow) {
    bat[curCol][curRow] = 2;
    for (int i = 0; i < sizeof(dirCol); i++) {
        newCol = curCol + dirCol[i];
        newRow = curRow + dirRow[i];
        if (newCol < 0 || newCol > col || newRow < 0 || newRow > row) {
            return;
        }
        if (bat[newCol][newRow] == 1) {
            bfs(bat, newCol, newRow);
        }
    }
}
int solution(int** bat) {
    int count = 0;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (bat[i][j] == 1) {
                bfs(bat, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N);
    int batchuNum;
    int colP, rowP;
    int batchu[50] = {};
    int* bat[50] = {};
    for (int i = 0; i < 50; i++) {
        bat[i] = (int*)malloc(sizeof(batchu));
    }
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &col, &row, &batchuNum);

        for (int j = 0; j < batchuNum; j++) {
            scanf("%d %d", &colP, &rowP);
            bat[colP][rowP] = 1;
        }
        batchu[i] = solution(bat);

        for (int j = 0; j < col; j++) {
            for (int k = 0; k < row; k++) {
                bat[j][k] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d\n", batchu[i]);
    }
}