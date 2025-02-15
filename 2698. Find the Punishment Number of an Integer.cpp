class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int e = i*i;
            string s = to_string(e);
            s += '0';
            int sz = s.size();
            vector<int> v[sz];
            v[sz-1].push_back(0);
            
            for(int i = sz-2; i >= 0; i--) {
                e = 0;
                for(int j = i; j < sz-1; j++) {
                    e = e*10 + (s[j] - '0');
                    for(int ch : v[j+1]) {
                        v[i].push_back(ch+e);
                    }
                }
            }
            
            for(int ch : v[0]) {
                if(ch == i) {
                    ans += i*i;
                    break;
                } 
            }
        }
        return ans;
    }
};
