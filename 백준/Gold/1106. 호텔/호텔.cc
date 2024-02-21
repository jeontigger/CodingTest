#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Ad {
public:
    int c, w;

    Ad() { }

    Ad(int c, int w) {
        this->c = c;
        this->w = w;
    }
};

int knapsack(vector<Ad> ads, int C, int N) {
    const int INF = 1000000;

    vector<int> dist(1100, INF);
    dist[0] = 0;

    for (Ad ad : ads) {
        for (int j = 1; j < 1100; j++) {
            if (j - ad.w > -1) {
                dist[j] = min(dist[j], dist[j - ad.w] + ad.c);
            }
        }
    }

    int ans = dist[C];

    for (int i = C + 1; i < 1100; i++) {
        ans = min(ans, dist[i]);
    }

    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C, N; cin >> C >> N;
    vector<Ad> ads(N, Ad());

    for (int i = 0; i < N; i++) {
        int c, w; cin >> c >> w;
        ads[i] = Ad(c, w);
    }

    cout << knapsack(ads, C, N);
   
    return 0;
}