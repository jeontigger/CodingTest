#include <string>
#include <vector>

using namespace std;

int first[] = {1, 2, 3, 4, 5};
int second[] = {2, 1, 2, 3, 2, 4, 2, 5};
int third[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnts[] = {0, 0, 0};
    int maxCnt = 0;
    for(int i = 0 ; i < answers.size(); i++){
        
        if(first[i%5] == answers[i])
            cnts[0]++;
        if(second[i%8] == answers[i])
            cnts[1]++;
        if(third[i%10] == answers[i])
            cnts[2]++;
        
        maxCnt = max(cnts[0], max(cnts[1], cnts[2]));
    }
    
    for(int i = 0; i < 3; i++){
        if(cnts[i] == maxCnt)
            answer.push_back(i+1);
    }
    
    return answer;
}