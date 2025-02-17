class Solution {
public:
    map<string,int> ma;
    int ans = 0;
    
    void solve(string s,int p,vector<int> &cnt) {
        if(s.size() == p) {
            if(ma[s] == 0) ans++;
            ma[s] = 1;
            return;
        }
        for(int i = 0; i < 26; i++) {
            if(cnt[i]) {
                s += ('A'+i);
                cnt[i]--;
                solve(s,p,cnt);
                s.pop_back();
                cnt[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> cnt(26,0);
        for(char ch : tiles) cnt[ch-'A']++;
        for(int i = 1; i <= tiles.size(); i++) {
            solve("",i,cnt);
        }
        return ans;
    }
};

---------------------------------------------------------------------------------

class Solution {
public:
    map<string,int> ma;
    
    int fac(int p) {
        int res = 1;
        for(int i = 2; i <= p; i++) res *= i;
        return res;
    }

    int cnt(string s) {
        vector<int> v(26,0);
        for(int ch : s) v[ch-'A']++;
        int ans = fac(s.size());
        for(int i = 0; i < 26; i++) ans /= fac(v[i]);
        return ans;
    } 

    int solve(string s,string &p,int pos) {
        if(pos == p.size()) {
            if(s.size() == 0 or ma[s]) return 0;
            ma[s] = 1;
            return cnt(s);
        }

        return (solve(s+p[pos],p,pos+1) + solve(s,p,pos+1));

    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        return solve("",tiles,0);
    }
};
