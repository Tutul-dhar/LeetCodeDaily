class Solution {
public:
    vector<vector<int>> g;
    vector<int> grp,and_val,vis;

    void dfs(int node,int group) {
        grp[node] = group;
        vis[node] = 1;
        

        for(auto it : g[node]) {
            if(vis[it] == 0) {
                dfs(it,group);
            }
        }

    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        g.resize(n+1);
        grp.resize(n+1,0);
        and_val.resize(n+1,-1);
        vis.resize(n+1,0);
        vector<vector<int>> v(n+1);
        for(auto it : edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
            v[it[0]].push_back(it[2]);
        }
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(i,i+1);
            }
        }
        for(int i = 0; i < n; i++) {
            int p = grp[i];
            if(and_val[p] == -1) {
                if(v[i].size()) and_val[p] = v[i][0];
            }
            for(int ch : v[i]) and_val[p] &= ch;
        }
        vector<int> ans;
        for(auto it : query) {
            if(grp[it[0]] == grp[it[1]]) ans.push_back(and_val[grp[it[0]]]);
            else ans.push_back(-1);
        }
        return ans;
    }
};

----------------------------------------------------------

class Solution {
private:
    vector<int> parent, rank;
public:
    int find(int u) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u]);
    }
    void _union(int u,int v) {
        int par1 = find(u);
        int par2 = find(v);
        if(par1 == par2) return;
        if(rank[par1] < rank[par2]) swap(par1,par2);

        parent[par2] = par1;
        if(rank[par1] == rank[par2]) rank[par1]++;
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n+1,-1);
        rank.resize(n+1,0);
        
        vector<int> res,ans(n+1,-1);
        for(auto it : edges) {
            int u = it[0],v = it[1];
            _union(u,v);
        }
        for(auto it : edges) {
            int u = it[0],value = it[2];
            int par = find(u);
            if(ans[par] == -1) ans[par] = value;
            else ans[par] &= value;
        }
        for(auto it : query) {
            int u = it[0],v = it[1];
            int par1 = find(u);
            int par2 = find(v);
            if(par1 == par2) res.push_back(ans[par1]);
            else res.push_back(-1);
        }
        return res;
    }
};
