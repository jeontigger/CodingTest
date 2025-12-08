class Solution {
public:
    unordered_map<string, multiset<string>> edges;
    vector<string> ret;

    void DFS(const string& from){
        
        while(!edges[from].empty()){
            auto iter = edges[from].begin();
            string to = *iter;
            edges[from].erase(iter);
            DFS(to);
        }
        ret.push_back(from);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i = 0 ; i < tickets.size(); i++){
            string s1 = tickets[i][0], s2 = tickets[i][1];
            edges[s1].insert(s2);
        }

        DFS("JFK");

        reverse(ret.begin(), ret.end());
        return ret;
    }
};