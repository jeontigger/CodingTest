class Solution {
public:
    string largestNumber(vector<int>& nums) {
        struct CMP{
            bool operator()(const string& str1, const string& str2){
                return str1 + str2 > str2 + str1;
            }
        };
        CMP cmp;
        vector<string> strings;
        strings.resize(nums.size());
        for(int i =0; i<strings.size();i++){
            strings[i] = to_string(nums[i]);
        }

        sort(strings.begin(), strings.end(), cmp);
        // for(string str:strings){
        //     cout << str << " " ;
        // }
        // cout << endl;

        string res = "";
        for(string str:strings){
            res += str;
        }

        if(res[0] == '0'){
            return "0";
        }

        return res;
    }
};