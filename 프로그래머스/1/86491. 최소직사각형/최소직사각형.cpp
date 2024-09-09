#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int small_max = 0;
    int big_max = 0;
    for(int i = 0; i<sizes.size();i++){
        int small = min(sizes[i][0], sizes[i][1]);
        int big = max(sizes[i][0], sizes[i][1]);
        
        small_max = max(small_max, small);
        big_max = max(big_max, big);
    }
    
    answer = small_max * big_max;
    
    return answer;
}