class Solution {
public:
    void printQ(list<char> q, unordered_map<char, int> m){
        for(auto iter = q.begin(); iter != q.end(); ++iter){
            cout<< *iter ;
        }

        cout <<"  ";

        for(pair<char, int> p:m){
            cout << p.first << ": " << p.second << "   ";
        }
        cout << endl;
    }

    string minWindow(string s, string t) {
        if(s.find(t) != std::string::npos){
            return t;
        }
        unordered_map<char, int> m;
        for(int i = 0; i < t.length(); i++){
            m[t[i]]++;
        }

        int leftIdx = 0;
        int rightIdx = 0;
        int cnt = t.length();
        string res = "";

        while(leftIdx <= rightIdx){
            // 빼는 작업
            // 언제?
            // t에 해당하는 글자 까지
            while(leftIdx < rightIdx){
                char c = s[leftIdx];
                leftIdx++;

                m[c]++;
                if(m[c] > 0){
                    cnt++;
                }

                c = s[leftIdx];
                if(m.find(c) != m.end()){
                    break;
                }
            }

            // cout << "OUT ===========================" << endl;
            // cout << s.substr(leftIdx, rightIdx - leftIdx) << endl;

            if(cnt == 0){
                if(rightIdx - leftIdx < res.length() || res == ""){
                    res = s.substr(leftIdx, rightIdx - leftIdx);
                }
            }

            while(rightIdx < s.length() && cnt != 0){
                
                char c = s[rightIdx];
                rightIdx++;

                if(m[c] > 0){
                    cnt--;
                }
                m[c]--;
                if(cnt == 0){
                    break;
                }
            }
            // cout << "PUSH===========================" << endl;
            // cout << s.substr(leftIdx, rightIdx - leftIdx) << " LEFT: " << leftIdx << " RIHGT: " << rightIdx << endl;

            if(cnt == 0){
                if(rightIdx - leftIdx < res.length() || res == ""){
                    res = s.substr(leftIdx, rightIdx - leftIdx);
                }
            }else{
                break;
            }
        }
        return res;
    }
};