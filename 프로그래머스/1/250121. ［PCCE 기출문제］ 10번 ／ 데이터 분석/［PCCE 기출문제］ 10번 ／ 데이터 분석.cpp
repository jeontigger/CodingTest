#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GetIdx(string str){
    int idx = -1;
    if(str == "code"){
        idx = 0;
    }else if(str == "date"){
        idx = 1;
    }else if(str == "maximum"){
        idx = 2;
    }else if(str == "remain"){
        idx = 3;
    }
    
    return idx;
}
int sortIdx;

bool cmp(const vector<int>& v1, const vector<int>& v2){
    return v1[sortIdx] < v2[sortIdx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int extIdx = GetIdx(ext);
    
    for(int i = 0 ; i < data.size(); i++){
        int val = data[i][extIdx];
        if(val < val_ext){
            answer.push_back(data[i]);
        }
    }
    
    sortIdx = GetIdx(sort_by);
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}