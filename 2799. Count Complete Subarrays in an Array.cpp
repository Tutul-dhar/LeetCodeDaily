class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int total_uni = 0;
        vector<int> a(2010,0);
        for(int ch : nums) {
            if(a[ch] == 0) total_uni++;
            a[ch]++;
        }
        for(int ch : nums) a[ch] = 0;
        int n = nums.size(),i = 0,j = 0,p = 0,ans = 0;
        while(j < n) {
            if(a[nums[j]] == 0) p++;
            a[nums[j]]++;
            j++;
            while(total_uni == p and i < j) {
                ans += (n - j + 1);
                a[nums[i]]--;
                if(a[nums[i]] == 0) p--;
                i++;
            }
        }
        return ans;
    }
};
