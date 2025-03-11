class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<vector<int>> v(3);
        int ans = 0,n = s.size();
        for(int i = n-1; i >= 0; i--) {
            int e = s[i] - 'a';
            v[e].push_back(i);
        }
        for(int i = 0; i < n; i++) {
            if(v[0].size() and v[1].size() and v[2].size()) {
                int p = max({v[0].back(),v[1].back(),v[2].back()});
                ans += (s.size() - p);
            }
            int  e = s[i] - 'a';
            v[e].pop_back();
        }
        return ans;
    }
};
