class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n);
        int mod = 1e9+7;
        for(auto it : roads) {
            g[it[0]].push_back({it[1],it[2]});
            g[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        vector<int> way(n,0);
        vector<long long> dis(n);
        for(int i = 0; i < n; i++) dis[i] = 1e13;
        way[0] = 1;
        while(!pq.empty()) {
            auto it = pq.top();
            long long diss = it.first;
            int node = it.second;
            pq.pop();

            for(auto it : g[node]) {
                int p = it.first;
                long long q = it.second;
                if(diss+q < dis[p]) {
                    dis[p] = diss+q;
                    way[p] = way[node];
                    way[p] %= mod;
                    pq.push({dis[p],p});
                } else if(diss+q == dis[p]) {
                    way[p] += way[node];
                    way[p] %= mod;
                    //pq.push({dis[p],p});
                }
            }
        }

        return way[n-1];
    }
};
