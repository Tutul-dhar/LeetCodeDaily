class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> v(40,0);
        int mx = 0;
        for(int i= 1; i <= n; i++) {
            int p = 0,q = i;
            while(q) {
                p += q%10;
                q/=10;
            }
            v[p]++;
            mx = max(mx,v[p]);
        }
        
        int ans = 0;
        for(int i = 0; i < 40; i++) {
            if(v[i] == mx) ans++;
        }
        return ans;
    }
};
