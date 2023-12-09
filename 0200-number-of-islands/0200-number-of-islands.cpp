class Solution {
public:
    void init(vector<bool>& confirm, const vector<vector<char>>& grid){
        confirm.resize(grid.size()*grid[0].size());

        for(int i = 0; i< confirm.size();i++){
            int row = i / grid[0].size();
            int col = i % grid[0].size();
            if(grid[row][col] == '0'){
                confirm[i] = true;
            }
        }        
    }

    void printConfirm(vector<bool>& confirm, int size){

        int cnt = 0;
        for(bool b: confirm){
            cout << b << " ";
            cnt++;
            if(size <= cnt){
                cout <<endl;
                cnt = 0;
            }
        }
    }

    // bfs로 풀기
    int numIslands(vector<vector<char>>& grid) {
        queue<int> task;
        
        vector<bool> confirm;

        init(confirm, grid);
        int arr[4];
        arr[0] = -1;
        arr[1] = 1;
        arr[2] = -grid[0].size();
        arr[3] = grid[0].size();

        int res = 0;
        printConfirm(confirm, grid[0].size());
        for(int i = 0 ; i<confirm.size();i++){
            if(confirm[i] == false){
                task.push(i);
                res++;
                cout << endl;
                // printConfirm(confirm, grid[0].size());
                // cout << "=========================== " << res-1 << endl;
            }

            while(!task.empty()){
                int pos = task.front();
                task.pop();

                confirm[pos] = true;
                cout << pos << " ";

                int row = pos / grid[0].size();
                int col = pos % grid[0].size();


                // 4방향 검사 - pos - 1,  pos + 1, pos + col , pos - col
                for(int j =0; j<4; j++){
                    if(pos % grid[0].size() == 0 && j == 0){
                        continue;
                    }else if(pos % grid[0].size()== grid[0].size()-1 && j == 1){
                        continue;
                    }
                    int dir = pos + arr[j];
                    if(0<=dir && dir <confirm.size()){
                        if(!confirm[dir]){
                            confirm[dir] = true;
                            task.push(dir);
                        }
                    }
                }
            }

        }
        // cout << endl;
        // printConfirm(confirm, grid[0].size());
        // cout << "=========================== " << res << endl;

        return res;

    }
};