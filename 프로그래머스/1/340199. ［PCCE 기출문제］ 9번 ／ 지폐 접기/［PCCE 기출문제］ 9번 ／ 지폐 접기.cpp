#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    // 항상 [1]이 [0]보다 큼
    if(wallet[0] > wallet[1]) swap(wallet[0], wallet[1]);
    if(bill[0] > bill[1]) swap(bill[0], bill[1]);
    
    while(true){
        if(bill[1] <= wallet[1] && bill[0] <= wallet[0]){
            break;
        }
        
        bill[1] /= 2;
        if(bill[0] > bill[1]) swap(bill[0], bill[1]);
        answer++;
    }
    return answer;
}