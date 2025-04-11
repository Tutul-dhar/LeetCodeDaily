class Solution {
private:
    int dp[6][40][6][2];
    int solve(int pos,int sum,int len,int ok,string& s) {
        if(sum < 0) return 0;
        if(pos == len) {
            return sum == 0;
        }
        if(dp[pos][sum][len][ok] != -1) return dp[pos][sum][len][ok];
        int high = s[pos] - '0';
        if(ok) high = 9;
        int ans = 0;
        int low = 0;
        if(pos == 0) low = 1;
        for(int i = low; i <= high; i++) {
            if(i < high) {
                if(pos < len/2) ans += solve(pos+1,sum+i,len,1,s);
                else ans += solve(pos+1,sum-i,len,1,s);
            }
            else {
                if(pos < len/2) ans += solve(pos+1,sum+i,len,ok,s);
                else ans += solve(pos+1,sum-i,len,ok,s);
            }
        }
        return dp[pos][sum][len][ok] = ans;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        memset(dp,-1,sizeof dp);
        int res = 0;
        low--;
        string p = to_string(low);
        string q = to_string(high);

        for(int i = 2; i <= 4; i += 2) {
            if(i > q.size()) break;
            if(i == q.size()) {
                res += solve(0,0,i,0,q);
            } else {
                res += solve(0,0,i,1,q);
            }
        }
        //cout << res << endl;
        memset(dp,-1,sizeof dp);
        for(int i = 2; i <= 4; i += 2) {
            if(i > p.size()) break;
            if(i == p.size()) {
                res -= solve(0,0,i,0,p);
            } else {
                res -= solve(0,0,i,1,p);
            }
        }

        return res;
    }
};
