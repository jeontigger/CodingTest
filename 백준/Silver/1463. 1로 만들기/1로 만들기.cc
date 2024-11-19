#include <iostream>
#include <queue>
#include <vector>

int closure[1000001];

int main() {
    int N;
    std::cin >> N;

    std::queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int i = q.front();
        if (i == N) break;

        q.pop();
        if (i * 3 < 1000001 && !closure[i * 3]) {
            q.push(i * 3);
            closure[i * 3] = closure[i] + 1;
        }
        if (i * 2 < 1000001 && !closure[i * 2]) {
            q.push(i * 2);
            closure[i * 2] = closure[i] + 1;
        }
        if ((i + 1) < 1000001 && !closure[i + 1]) {
            q.push(i + 1);
            closure[i + 1] = closure[i] + 1;
        }
    }
    std::cout << closure[N] << std::endl;
}