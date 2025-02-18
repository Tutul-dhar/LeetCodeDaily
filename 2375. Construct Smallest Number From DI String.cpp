class Solution {
public:
    bool check(string &s,char ch) {
        for(char ch1 : s) {
            if(ch == ch1) return false;
        }
        return true;
    }
    void solve(string &q,string &p,string &ans,vector<int> &used,int pos=0) {
        if(pos == p.size()) {
            ans = min(ans,q);
            return;
        }
        for(char ch = '1'; ch <= '9'; ch++) {
            if(p[pos] == 'I' and q.back() < ch and check(q,ch)) {
                q += ch;
                used[ch-'0'] = 1;
                solve(q,p,ans,used,pos+1);
                used[ch-'0'] = 0;
                q.pop_back();
            } 
            if(p[pos] == 'D' and q.back() > ch and check(q,ch)) {
                q += ch;
                used[ch-'0'] = 1;
                solve(q,p,ans,used,pos+1);
                used[ch-'0'] = 0;
                q.pop_back();
            }
        }
    }
    string smallestNumber(string pattern) {
        string s="";
        for(char ch : pattern) s += '9';
        vector<int> used(10,0);
        for(int i = 1; i <= 9; i++) {
            string ss = to_string(i);
            solve(ss,pattern, s,used);
        }
        return s;
    }
};
