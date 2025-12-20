class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> versions1, versions2;
        stringstream ss1(version1), ss2(version2);
        string token;
        while(getline(ss1, token, '.')){
            versions1.push_back(stoi(token));
        }
        while(getline(ss2, token, '.')){
            versions2.push_back(stoi(token));
        }

        for(int i = 0 ; i < versions1.size() && i < versions2.size(); i++){
            if(versions1[i] < versions2[i]) return -1;
            else if(versions1[i] > versions2[i]) return 1;
        }

        while(!versions1.empty() && versions1.back() == 0){
            versions1.pop_back();
        }
        while(!versions2.empty() && versions2.back() == 0){
            versions2.pop_back();
        }

        if(versions1.size() < versions2.size())
            return -1;
        else if(versions1.size() > versions2.size())
            return 1;
        return 0;
    }
};