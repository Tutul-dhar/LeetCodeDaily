class Solution {
private:
    vector<vector<int>> g;
    vector<int> vis, inDegree,inStack;
    int n, ans;

    bool checkCircle(int node) {
        vis[node] = 1;
        inStack[node] = 1;

        for (int ch : g[node]) {
            if (!vis[ch]) {
                if (checkCircle(ch))
                    return true;
            } else if (inStack[ch]) {
                return true;
            }
        }

        inStack[node] = 0;
        return false;
    }

    void findMax(int node, string& s,vector<vector<int>> &a) {
        queue<int> q;
        q.push(node);
        while(q.size()) {
            int p = q.front();
            q.pop();
            a[p][s[p]-'a']++;
            ans = max(ans,a[p][s[p]-'a']);
            for(int ch : g[p]) {
                for(int i = 0; i < 26; i++) a[ch][i] = max(a[ch][i],a[p][i]);
                inDegree[ch]--;
                if(inDegree[ch] == 0) q.push(ch);
            }
        }
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n = colors.size();
        g.resize(n + 1);
        vis.resize(n + 1);
        inStack.resize(n+1);
        inDegree.resize(n + 1);
        vector<vector<int>> a(n,vector<int>(26,0));
        for (auto it : edges) {
            if (it[0] == it[1])
                return -1;
            g[it[0]].push_back(it[1]);
            inDegree[it[1]]++;
        }
        vector<int> v;
        for (int i = 0; i < n; i++) {
            
            if (inDegree[i] == 0)
                v.push_back(i);
            if (vis[i])
                continue;
            if (checkCircle(i))
                return -1;
        }
        ans = 1;
        
        for (int ch : v) {
            findMax(ch, colors,a);
        }
        return ans;
    }
};
