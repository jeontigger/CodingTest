#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    int side = brown;
    side += 4;
    int halfsum = side/2;
    
    for(int i = ceil((float)halfsum/2); i < halfsum; i++){
        int horizen = i;
        int vertical = halfsum - i;
        
        int yhorizen = horizen - 2;
        int yvertical = vertical - 2;
        
        // cout << horizen << ' ' << vertical << '\n';
        if(yhorizen * yvertical == yellow)
        {
            answer[0] = horizen;
            answer[1] = vertical;
            break;
        }
        
    }
    
    
    return answer;
}