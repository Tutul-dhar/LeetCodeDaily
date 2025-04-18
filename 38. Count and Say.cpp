class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++) {
            string temp = "";
            int j = 0;
            while(j < ans.size()) {
                int k = j;
                int cnt = 0;
                while(k < ans.size() and ans[k] == ans[j]) {
                    k++;
                    cnt++;
                }
                string p = to_string(cnt);
                temp += p;
                temp += ans[j];
                j = k;
            }
            ans = temp;
        }
        return ans;
    }
};
