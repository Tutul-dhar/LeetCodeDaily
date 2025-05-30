class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> g(n);
        vector<int> dis(n),dis1(n);
        for(int i = 0; i < n; i++) {
            if(edges[i] != -1) g[i].push_back(edges[i]);
            dis[i] = 1e9;
            dis1[i] = 1e9;
        }
        dis[node1] = 0;
        dis1[node2] = 0;
        queue<int> q;
        q.push(node1);
        while(q.size()) {
            int node = q.front();
            q.pop();
            for(int ch : g[node]) {
                if(dis[node]+1 < dis[ch]) {
                    dis[ch] = dis[node] + 1;
                    q.push(ch);
                }
            }
        }

        q.push(node2);
        while(q.size()) {
            int node = q.front();
            q.pop();
            for(int ch : g[node]) {
                if(dis1[node]+1 < dis1[ch]) {
                    dis1[ch] = dis1[node] + 1;
                    q.push(ch);
                }
            }
        }

        int ans = -1,res = 1e9;
        for(int i = 0; i < n; i++) {
            int mx = max(dis[i],dis1[i]);
            if(mx < res) {
                ans = i;
                res = mx;
            }
        }
        return ans;
    }
};
