class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int next = 0,ans =0;
        int n = meetings.size();
        for(int i = 0; i < n; ) {
            int p = meetings[i][0] - next - 1;
            ans += p;
            int j = i;
            next = meetings[i][1];
            while(j < n and meetings[j][0] <= next) {
                next = max(next,meetings[j][1]);
                j++;
                
            }
            i = j;
        }
        ans += (days - next);
        return ans;
    }
};
