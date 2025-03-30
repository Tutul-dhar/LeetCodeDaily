class Solution {
private:
    bool check(vector<int> &cnt,vector<int> &a) {
        for(int i = 0; i < 26; i++) {
            if(cnt[i] and a[i]) return false;
        }
        return true;
    }
public:
    vector<int> partitionLabels(string s) {
        vector<int> cnt(26,0);
        for(char ch : s) {
            cnt[ch-'a']++;
        }
        int a = 0;
        vector<int> ans,b(26,0);

        for(int i = 0; i < s.size(); i++) {
            a++;
            b[s[i]-'a']++;
            cnt[s[i]-'a']--;
            if(check(cnt,b)) {
                ans.push_back(a);
                a = 0;
                for(int j = 0; j < 26; j++) b[j] = 0;
            }
            

        }
        return ans;
    }
};
