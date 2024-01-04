class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;
        priority_queue<pair<int, char>> pq;

        for(int i = 0; i < tasks.size(); i++){
            map[tasks[i]]++;
        }

        for(auto pair:map){
            pq.push({pair.second, pair.first});
        }

        int res = 0;

        while(!pq.empty()){

            list<pair<int, char>> q;
            int cnt = 0;
            for(int i = 0; i<n+1;i++){
                if(pq.empty()){
                    break;
                }else{
                    auto p = pq.top();
                    pq.pop();
                    p.first--;
                    cnt++;
                    if(p.first!=0){
                        q.push_back(p);
                    }
                }
            }
            if(q.empty()&& pq.empty()){
                cout << cnt << endl;
                res+=cnt;
                break;
            }
            res+=n+1;

            while(!q.empty()){
                auto p = q.front();
                q.pop_front();
                pq.push(p);
            }
        }

        auto tmpPQ = pq;
        while(!tmpPQ.empty()){
            auto p = tmpPQ.top();
            cout << p.first << " " << p.second << endl;
            tmpPQ.pop();
        }

        return res;
    }
};