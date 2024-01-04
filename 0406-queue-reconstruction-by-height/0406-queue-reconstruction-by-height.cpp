class Solution {
public:
    void printVecVec(const vector<vector<int>>& vec){
        for(vector<int> v:vec){
            for(int i:v){
                cout << i << " ";
            }
            cout << endl;
        }
        cout << "===================" << endl;
    }

    void printList(const list<vector<int>>& list){
        for(vector<int> v:list){
            for(int i:v){
                cout << i << " ";
            }
            cout << endl;
        }
        cout << "=====================" << endl;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // printVecVec(people);

        sort(people.begin(), people.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] != v2[0] ? v1[0] > v2[0] : v1[1] < v2[1];
        });

        vector<vector<int>> res;
        res.reserve(people.size());

        for(vector<int> vec: people){
            res.insert(res.begin() + vec[1], vec);
        }



        return res;
    }
};