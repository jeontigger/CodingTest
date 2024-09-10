#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // 총 주문된 목록 구하기
    string alphaList = "";
    for(auto& str:orders){
        alphaList += str;
    }
    sort(alphaList.begin(), alphaList.end());
    alphaList.erase(unique(alphaList.begin(), alphaList.end()), alphaList.end());
    
    
    for(int k = 0; k < course.size();k++){
        unordered_map<string, int>m;
        vector<bool> check;
        for(int i = 0; i < alphaList.size(); i++){
            if(i < course[k]){
                check.push_back(true);
            }else{
                check.push_back(false);
            }

        }
        reverse(check.begin(), check.end());
        do{
            // 탐색할 리스트 만들기
            string strSearch;
            for(int i = 0; i<alphaList.size();i++){
                if(check[i]){
                    strSearch += alphaList[i];
                }
            }

            // 개수 판정
            for(int i = 0; i < orders.size();i++){
                bool bOrder = true;
                for(int j = 0; j < strSearch.length(); j++){
                    auto iter = orders[i].find(strSearch[j]);
                    if(iter == string::npos){
                        bOrder = false;
                        break;
                    }
                }
                if(bOrder){
                    m[strSearch]++;
                }
            }
        }while(next_permutation(check.begin(), check.end()));

        // 제일 많은 개수 찾기
        int iMax = 0;
        for(auto&p : m){
            iMax = max(iMax, p.second);
        }

        // 제일 많은 개수에 해당하는 코스 찾기
        for(auto& p: m){
            if(p.second == iMax && iMax > 1){
                answer.push_back(p.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}