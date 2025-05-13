class Solution {
    private:
    int mod = 1e9+7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> a(26,0);
        int ans = 0;

        for(char ch : s) a[ch-'a']++;

        for(int i = 0; i < t; i++) {
            vector<int> b(26,0);
            for(int j = 0; j < 25; j++) b[j+1] += a[j];
            b[0] += a[25];
            b[1] =(b[1] + a[25])%mod;
            swap(a,b);
        }

        for(int ch : a) ans = (ans + ch)%mod;
        return ans;
    }
};
