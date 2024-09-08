#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    vector<int>::iterator it;
    
    for(it = arr.begin(); it!=arr.end();it++){
        if((it+1)==arr.end())
        {
            answer.push_back(*it);
            break;
        }
        if(*it==*(it+1))
            continue;
        answer.push_back(*it);
        
    }

    return answer;
}