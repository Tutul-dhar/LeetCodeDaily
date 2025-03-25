class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> x,y;
        int m = rectangles.size();
        for(auto it : rectangles) {
            x.push_back({it[0],it[2]});
            y.push_back({it[1],it[3]});
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int cnt = 0,cnt1 = 0;
        int mx = x[0].second;
        for(int i = 1; i < m; i++) {
           if(x[i].first >= mx) {
               mx = x[i].second;
               cnt++;
           } else mx = max(mx,x[i].second);
        }

        mx = y[0].second;
        for(int i = 1; i < m; i++) {
           if(y[i].first >= mx) {
               mx = y[i].second;
               cnt1++;
           } else mx = max(mx,y[i].second);
        }
        //cout << cnt << ' ' << cnt1 << endl;
        if(cnt >= 2 or cnt1 >= 2) return true;
        return false;
    }
};
