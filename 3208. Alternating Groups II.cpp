class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int> pre;
        int n = colors.size();
        pre.push_back(0);
        for(int i = 1; i < 2*n; i++) {
            int p = i%n;
            int q = (p+n-1)%n;
            //cout << p << ' ' << q << endl;
            if(colors[q] == colors[p]) pre.push_back(1);
            else pre.push_back(0);
            pre[i] += pre[i-1];
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int e = pre[i+k-1];
            e -= pre[i];
            if(e == 0) ans++;
        }
        return ans;
    }
};
