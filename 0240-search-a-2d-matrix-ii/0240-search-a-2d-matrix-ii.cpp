class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // row부터 찾아
        // col 갱신
        // row 줄여가며 col 갱신
        if(target < matrix[0][0] || matrix[matrix.size()-1][matrix[0].size()-1] < target) return false;

        int row = -1;
        for(int i =0; i<matrix.size();i++){
            if(matrix[matrix.size()-1 - i][0] <= target){
                row = matrix.size() - 1 - i;
                break;
            }
        }
        
        int left = 0;
        for(int i = 0; i <= row ; i++){
            for(int j = left; j < matrix[0].size(); j++){
                if(matrix[row-i][j] < target) left = j;
                if(target == matrix[row-i][j]) return true;
                if(target < matrix[row-i][j]){
                    break;
                }
            }
        }

        
        return false;
    }
};