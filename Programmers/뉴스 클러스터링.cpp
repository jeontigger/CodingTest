#include <string>
#include <iostream>
#include <cctype>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <tgmath.h>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    multiset<pair<int, int>> mset1;
    multiset<pair<int, int>> mset2;
    
    int msetSize1 = 0;
    int msetSize2 = 0;
    
    for(int i = 0; i<str1.length()-1; i++){
        char c1 = str1[i];
        char c2 = str1[i+1];
        
        if(isalpha(c1) && isalpha(c2)){
            mset1.insert({tolower(c1), tolower(c2)});
            msetSize1++;
        }
    }
    
    for(int i = 0; i<str2.length()-1; i++){
        char c1 = str2[i];
        char c2 = str2[i+1];
        
        if(isalpha(c1) && isalpha(c2)){
            mset2.insert({tolower(c1), tolower(c2)});
            msetSize2++;
        }
    }
    
    cout << msetSize1 << " " << msetSize2 << endl;
    if(msetSize1 == 0 && msetSize2 == 0){
        return 65536;
    }
    
    int crossCnt = 0;
    for(auto iter = mset1.begin(); iter!= mset1.end();){
        auto findIter = find(mset2.begin(), mset2.end(), *iter);
        if(findIter != mset2.end()){
            crossCnt++;
            iter = mset1.erase(iter);
            mset2.erase(findIter);
        }else{
            ++iter;
        }
    }
    
    answer = int(float(crossCnt) / (msetSize1 + msetSize2 - crossCnt) * 65536);
    return answer;
}