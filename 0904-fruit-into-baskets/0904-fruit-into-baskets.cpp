class Solution {
public:
    unordered_map<int, int> cnts;
    set<int> kinds;

    int totalFruit(vector<int>& fruits) {
        int ret = 0, left = 0;

        for(int right = 0; right < fruits.size(); right++){
            cnts[fruits[right]]++;
            kinds.insert(fruits[right]);

            while(kinds.size() > 2){
                cnts[fruits[left]]--;
                if(cnts[fruits[left]] == 0){
                    kinds.erase(fruits[left]);
                }
                left++;
            }

            ret = max(ret, right - left + 1);
        }


        return ret;
    }
};