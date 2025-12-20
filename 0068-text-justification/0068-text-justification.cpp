class Solution {
public:
    void PrintLines(const vector<vector<string>>& lines) {
        for (auto& vec : lines) {
            for (auto& str : vec) {
                cout << str << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    int GetLen(const vector<string>& strings) {
        int ret = 0;
        for (const auto& str : strings)
            ret += str.size();
        return ret;
    }

    vector<string> PutSpace(const vector<vector<string>>& lines, int maxWidth) {
        vector<string> ret(lines.size(), string(maxWidth, ' '));

        // 확장 정렬
        for (int i = 0; i < lines.size()-1; i++) {
            int remain = maxWidth - GetLen(lines[i]);
            int offset = 0;
            for (int j = 0; j < lines[i].size(); j++) {
                const string& str = lines[i][j];
                // cout << offset << ' ';
                for (int k = 0; k < str.size(); k++) {
                    if(k + offset >= ret[i].size()){
                        // cout << '\n'<< i << ' ' << j << ' ' << str << ' ' << k << ' ' << offset << '\n';
                        continue;
                    }
                    ret[i][k + offset] = str[k];
                }
                offset += str.size();

                // 2 단어 이상만 계산
                int len = lines[i].size();
                if(len > 1){
                    offset += remain / (len-1);
                    int quot = remain % (len - 1);
                    if(quot != 0 && j < quot){
                        offset++;
                    }
                }
                // cout << offset << ' ';
            }
            // cout << '\n';
        }

        // 마지막 줄
            int offset = 0;
        for(int i = 0; i < lines.back().size(); i++){
            const string& str = lines.back()[i];
            for(int j = 0; j < str.size(); j++){
                ret.back()[j+offset] = str[j];
            }
            offset += str.size();
            offset++;
        }


        return ret;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // this is an example
        // 스페이스바는 앞에서부터 크게 채우는건가? => 3개 남았을 때 2칸 채워야
        // 하면 2, 1처럼 마지막 줄만 왼쪽 정렬
        int accSize = maxWidth + 1;
        vector<vector<string>> lines;
        for (int i = 0; i < words.size(); i++) {
            int nextAccSize = accSize + words[i].size() + 1;
            if (nextAccSize > maxWidth) {
                // 다음줄
                accSize = words[i].size();
                lines.push_back({});
            } else {
                // 현재 줄 추가
                accSize = nextAccSize;
            }
            lines.back().push_back(words[i]);
        }

        // space 집어넣기

        // PrintLines(lines);
        return PutSpace(lines, maxWidth);
    }
};