class Solution {
public:

    unordered_map<string, vector<int>> g_map;
    vector<vector<string>> g_tickets;
    vector<string> res;

    void Recursive(const string& arrival){
        
        for(int i =0; i< g_map[arrival].size();i++){
            int idx = g_map[arrival][i];
            if(g_map[arrival][i] != -1){
                g_map[arrival][i] = -1;
                Recursive(g_tickets[idx][1]);
            }
        }
        res.push_back(arrival);

    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        sort(tickets.begin(), tickets.end());
        g_tickets = tickets;

        for(int i =0; i<tickets.size();i++){
            g_map[tickets[i][0]].push_back(i);
        }

        Recursive("JFK");
        for(vector<string> v:tickets){
            for(string str:v){
                cout << str<< " " ;
            }
            cout << endl;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};