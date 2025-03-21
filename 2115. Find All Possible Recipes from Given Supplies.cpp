class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        map<string,vector<int>> ma;
        vector<int> cnt(n,0);
        for(int i = 0; i < n; i++) {
            for(auto it : ingredients[i]) ma[it].push_back(i);
        }
        queue<string> q;
        for(auto it : supplies) {
            q.push(it);
        }
        vector<string> ans;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            for(int ch : ma[it]) {
                cnt[ch]++;
                if(cnt[ch] == ingredients[ch].size()) {
                    q.push(recipes[ch]);
                    ans.push_back(recipes[ch]);
                }
            }
        }
        return ans;
    }
};
