class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0,n = arr.size();
        unordered_set<int> s(arr.begin(),arr.end());
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int cnt = 2;
                int p = arr[j],q = arr[i];
                while(1) {
                    int e = p + q;
                    if(s.count(e)) {
                        cnt++;
                        p = q;
                        q = e;
                    } else break;
                }
                if(cnt > 2) ans = max(ans,cnt);
            }
        }
        return ans;
    }
};

----------------------------------------------------------------------------------

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0,n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i = 2; i < n; i++) {
            int l = 0,r = i-1;
            while(l < r) {
                if(arr[l] + arr[r] == arr[i]) {
                    dp[r][i] = max(dp[r][i],dp[l][r] + 1);
                    ans = max(ans,dp[r][i]);
                    l++;
                    r--;
                } else if(arr[l] + arr[r] > arr[i]) r--;
                else l++;

            }
        }
        if(ans) return ans + 2;
        return 0;
    }
};
