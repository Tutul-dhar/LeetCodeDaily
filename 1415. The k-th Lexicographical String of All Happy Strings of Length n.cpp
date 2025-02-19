class Solution {
public:
    set<string> s;

    void solve(string p,int n,int k) {
        if(p.size() == n) {
            s.insert(p);
            if(s.size() > k) {
                auto it = s.end();
                it--;
                s.erase(it);
            }
            return;
        }
        if(s.size() == k) {
            auto it = s.end();
            it--;
            if(*it < p) return;
        }
        for(char ch = 'a';ch <= 'c'; ch++) {
            if(p.size() == 0) {
                p += ch;
                solve(p,n,k);
                p.pop_back();
            } else if(p.back() != ch) {
                p += ch;
                solve(p,n,k);
                p.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        solve("",n,k);
        if(s.size() < k) return "";
        auto it = s.end();
        it--;
        return *it;
    }
};

--------------------------------------------------------------------

class Solution {
public:
    int cnt = 0;
    string ans = "";

    void solve(string p,int n,int k) {
        if(p.size() == n) {
            cnt++;
            if(cnt == k) {
                ans = p;
                
            }
            return;
        }
        if(cnt >= k) {
            return;
        }
        for(char ch = 'a';ch <= 'c'; ch++) {
            if(p.size() == 0) {
                p += ch;
                solve(p,n,k);
                p.pop_back();
            } else if(p.back() != ch) {
                p += ch;
                solve(p,n,k);
                p.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        solve("",n,k);
        return ans;
    }
};
