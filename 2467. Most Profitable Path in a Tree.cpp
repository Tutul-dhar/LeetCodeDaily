class Solution {
private:
    void solve(int node,int pa,vector<vector<int>> &v, vector<int> &depth, vector<int> &par) {
        par[node] = pa;
        if(pa != -1) depth[node] = depth[pa] + 1;
        for(int ch : v[node]) {
            if(ch != pa) solve(ch,node,v,depth,par);
        }
    }

    void dfs(int node,int pa, vector<vector<int>> &v, vector<int> &amount) {
        if(pa != -1) amount[node] += amount[pa];
        for(int ch : v[node]) {
            if(ch != pa) dfs(ch,node,v,amount);
        }
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int> depth(n,0),par(n,-1);
        vector<vector<int>> tree(n);
        for(auto it : edges) {tree[it[0]].push_back(it[1]);tree[it[1]].push_back(it[0]);}
        solve(0,-1,tree,depth,par);
        int p = depth[bob]+1;
        int dis = p/2;
        while(dis) {
            amount[bob] = 0;
            bob = par[bob];
            dis--;
        }
        if(p%2) amount[bob] /= 2;

        dfs(0,-1,tree,amount);
        int ans = -1e9;
        for(int i = 1; i < n; i++) {
            if(tree[i].size() == 1) ans = max(ans,amount[i]);
        }
        return ans;
    }
};
