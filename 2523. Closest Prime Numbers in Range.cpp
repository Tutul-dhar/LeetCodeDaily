class Solution {
public:
    int pp = 1000001;
    vector<int> prime,vis;
    void find_prime() {
        for(int i = 2; i <= 1000000; i++) {
            if(vis[i] == 0) {
                prime.push_back(i);
                for(int j = 2*i; j <= 1000000; j += i) vis[j] = 1;
            }
        }
    }
    bool ok = true;
    vector<int> closestPrimes(int left, int right) {
        if(ok) {
            vis.assign(pp,0);
            find_prime();
            ok = false;
        }
        int ind = lower_bound(prime.begin(),prime.end(),left) - prime.begin();
        int mx = 10000000,p = -1,q = -1;
        for(int i = ind+1; i < prime.size(); i++) {
            if(prime[i] > right) break;
            int e = prime[i] - prime[i-1];
            if(e < mx) {
                mx = e;
                p = prime[i-1];
                q = prime[i];
            }
        }

        return {p,q};
    }
};
