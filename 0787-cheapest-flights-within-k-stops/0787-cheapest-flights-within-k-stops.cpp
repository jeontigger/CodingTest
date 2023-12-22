class Solution {
public:
    vector<vector<int>> m_prices;
    int INF;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        INF = 100000000;
        vector<int> vec(n, INF);
        vector<vector<int>> graph(n, vec);
        m_prices = graph;
        vector<bool> visited(n);

        for(int i = 0; i<flights.size();i++){
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];

            m_prices[from][to] = price;
        }

        for(vector<int> v:m_prices){
            for(int i:v){
                cout<< i << " " ;
            }
            cout << endl;
        }
        cout << "=====================================" << endl;

        visited[src] = true;
        int changeCnt = 0;

        vector<int> able;
        vector<int> temp(n);
        for(int i =0; i<k;i++){
            temp = m_prices[src];
            for(int j = 0; j< n ; j++){
                if(visited[j])
                    continue;

                if(m_prices[src][j] < INF){
                    able.push_back(j);
                    visited[j] = true;
                }
            }

            for(int j = 0; j < able.size() ; j++){
                int targetRow = able[j];
                for(int k = 0; k < n ;k++){
                    int price = m_prices[targetRow][k];

                    if(m_prices[src][targetRow] + price < temp[k]){
                        temp[k] = m_prices[src][targetRow] + price;
                        visited[k] = false;
                    }
                }
            }

            m_prices[src] = temp;

            able.clear();



            // for(vector<int> v:m_prices){
            //     for(int i:v){
            //         cout<< i << " " ;
            //     }
            //     cout << endl;
            // }
            // cout << "=====================================" << endl;
        }

        if(m_prices[src][dst]==INF){
            return -1;
        }

        return m_prices[src][dst];
    }
};