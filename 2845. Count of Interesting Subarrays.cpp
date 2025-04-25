class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> a(n);
        map<int,int> ma;
        int total = 0,p = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i]%modulo == k) total++;
            a[i] = total%modulo;
            ma[a[i]]++;
        }
        long long ans = 0;
        total = 0;
        for(int i = 0; i < n; i++) {
            p = 0;
            if(i) p = a[i-1];
            p += k;
            p %= modulo;
            ans += (long long) ma[p];
            if(nums[i]%modulo == k) total++;
            p = total%modulo;
            ma[p]--;
        }
        return ans;
    }
};
