class Solution {
public:
    string a,b;
    
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(),m = str2.size();
        a = str1,b = str2;
        a = '0'+a;
        b = '0'+b;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 0; i <= m; i++) dp[0][i] = i;
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i] == b[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + 1;
                }
            }
        }
        
        int i = n,j = m;
        string ans= "";
        while(i > 0 or j > 0) {
            if(i-1 >= 0 and j-1 >= 0 and a[i] == b[j] and dp[i][j] == dp[i-1][j-1] + 1) {
                ans += a[i];
                i--;
                j--;
            } else if(i-1 >= 0 and dp[i][j] == dp[i-1][j] + 1) {
                ans += a[i];
                i--;
            } else {
                ans += b[j];
                j--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
