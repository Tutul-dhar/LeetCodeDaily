class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        map<pair<int,int>,int> ma;
        for(auto it : dominoes) {
            int a = it[0],b = it[1];
            if(a > b) swap(a,b);
            ans += ma[{a,b}];
            ma[{a,b}]++;
        }
        return ans;
    }
};
