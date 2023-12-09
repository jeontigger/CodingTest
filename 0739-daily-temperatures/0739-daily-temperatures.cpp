class Solution {
public:
    void printVec(vector<int>& vec){
      for(int i:vec){
        cout << i << " ";
      }
    }


    vector<int> dailyTemperatures(vector<int>& temperatures) {
            
        vector<int> res;
        res.resize(temperatures.size());

        list<pair<int, int>> stack;
        for(int i = 0; i<temperatures.size();i++){
            int temper = temperatures[i];
            if(stack.size()==0){
                stack.push_back({temper, i});
                continue;
            }
            
            while(true){
                pair<int, int> p = stack.back();
                
                int top = p.first;
                if(top < temper){
                    stack.pop_back();
                    res[p.second] = i - p.second;
                }else{
                    stack.push_back({temper, i});
                    break;
                }

                if(stack.empty()){
                    stack.push_back({temper, i});
                }
            }
        }


      
        return res;
    }









    // STL 타임아웃
    // vector<int> dailyTemperatures(vector<int>& temperatures) {
        
    //     vector<int> res;
    //     res.resize(temperatures.size());
    //     for(int i =0; i<temperatures.size();i++){
    //       int temper = temperatures[i];
    //       res[i] = 0;
    //       auto iter = find_if(temperatures.begin()+ i+ 1, temperatures.end(), [temper](int comp) {if(temper < comp){return true;}return false;});
    //       if(iter != temperatures.end()){
    //         res[i] = iter - temperatures.begin() - i;
    //       }

    //     }
    //     // printVec(res);
    //     return res;
    // }





    // 일반식 타임아웃
    // vector<int> dailyTemperatures(vector<int>& temperatures) {
        
    //     vector<int> res;
    //     res.resize(temperatures.size());
    //     for(int i =0; i<temperatures.size();i++){
    //       int temper = temperatures[i];
    //       res[i] = 0;
    //       for(int j = i+1; j < temperatures.size(); j++){
    //         int comp= temperatures[j];
    //         if(temper < comp){
    //           res[i] = j - i;
    //           break;
    //         }
    //       }

    //     }
    //     // printVec(res);
    //     return res;
    // }
};