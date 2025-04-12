#define ll long long
#define pb push_back
class Solution {
public:
    vector<ll> fact;
    unordered_map<string,ll> ma;
    ll ans = 0;

    string getFullString(string s,int val) {
        string t = s.substr(0,val);
        reverse(t.begin(),t.end());
        s += t;
        return s;
    }
    
    bool divisible(string &s,int k) {
        ll val = 0;
        for(int i = 0; i < s.size(); i++) {
            val = val*10ll + (s[i] - '0');
        }
        if(val%(ll)k) return false;
        return true;
    }
    ll cal_no(string &s) {
        vector<ll> fr(10,0);
        ll n = s.size();
        for(auto ch : s) fr[ch-'0']++;
        string p = "";
        ll res = fact[n];
        for(int i = 0; i < 10; i++) {
            p += ('a' + fr[i]);
            if(fr[i]) res /= fact[fr[i]];
        }
        if(ma.find(p) != ma.end()) return 0;
        ma[p] = 1;
        if(fr[0] == 0) return res;
        if(fr[0] > 0) {
            ll ans  = fact[n-1];
            ans /= fact[fr[0] - 1];
            for(int i = 1; i < 10; i++) {
                ans /= fact[fr[i]];
            }
            res -= ans;
        } 
        
        return res;
    }

    ll cal(int n,int k,string &s) {
        string p = getFullString(s,n/2);
        //cout << p << endl;
        
        if(divisible(p,k)) {
            return cal_no(p);
        }
        return 0;
    }

    long long countGoodIntegers(int n, int k) {
        ans = 0;
        
        ma.clear();
        fact.clear();
        ll p = 1;
        fact.pb(p);
        for(ll i = 1; i <= 11; i++) {
            p *= i;
            fact.pb(p);
        }
        
        p = 1;
        for(int i = 0 ; i < (n/2 + n%2); i++) {
            p *= 10ll;
        }
        for(ll j = p/10ll; j < p; j++) {
            
            string s = to_string(j);
            ans += cal(n,k,s);
        }
        
        
        return ans;
    }
};
