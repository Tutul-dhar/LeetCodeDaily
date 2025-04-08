class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> cnt(101,0);
        int p = 0;
        for(int ch : nums) {
            cnt[ch]++;
            if(cnt[ch] == 2) p++;
        }
        int ans = 0,i = 0,n = nums.size();

        while(i < n) {
            if(p <= 0) break;
            ans++;
            
            int e = 3;
            while(e and i < n) {
                cnt[nums[i]]--;
                if(cnt[nums[i]] == 1) p--;
                i++;
                e--;
            }
        }

        return ans;
    }
};
