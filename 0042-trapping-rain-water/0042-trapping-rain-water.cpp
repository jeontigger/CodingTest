class Solution {
public:
    int trap(vector<int>& height) {
        int maxH = 0;
        int curIdx = 0;
        vector<int> pounds;
        pounds.resize(height.size());

        for(int i = 0; i<height.size();i++){
            if(height[i] != 0){
                maxH = height[i];
                curIdx = i;
                break;
            }
        }
        

        for(int i = curIdx + 1; i<height.size();i++){
            int curH = height[i];
            if(curH >= maxH){
                for(int j = curIdx + 1 ; j < i; j++){
                    pounds[j] = maxH - height[j];
                }
                maxH = curH;
                curIdx = i;
            }
        }

        for(int i = height.size()-1 ; i >=0 ; i-- ){
            if(height[i] != 0){
                maxH = height[i];
                curIdx = i;
                break;
            }
        }

        for(int i = curIdx - 1; i >= 0 ; i--){
            int curH = height[i];
            if(curH >= maxH){
                for(int j = curIdx -1; j > i ; j--){
                    pounds[j] = maxH - height[j];
                }
                maxH = curH;
                curIdx = i;
            }
        }
        int res = 0;
        for(int i:pounds){
            res+= i;
        }
        return res;
    }
};