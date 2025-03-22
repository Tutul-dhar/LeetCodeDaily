class Solution {
private:
    vector<vector<int>> g;
    vector<int> vis;

// private:
//     void dfs(int node) {
//         vis[node] = 1;
//         for(int ch : g[node]) {
//             if(vis[ch] == 0) dfs(ch);
//         }
//     }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        g.resize(n);
        vis.resize(n,0);
        for(auto it : edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                queue<int> q;
                int cnt = 0;
                vector<int> v;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    cnt++;
                    v.push_back(node);
                    for(int ch : g[node]) {
                        if(vis[ch] == 0) {
                            vis[ch] = 1;
                            q.push(ch);
                        }
                    }
                }
                bool ok = true;
                for(int ch : v) {
                    if(g[ch].size() < cnt-1) ok = false;
                }
                if(ok) ans++;
            }
        }
        return ans;
    }
};
