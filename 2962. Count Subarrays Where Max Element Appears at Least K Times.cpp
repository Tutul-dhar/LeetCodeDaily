class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = 0,i = 0,j = 0,cnt = 0,n = nums.size();
        long long ans = 0;
        for(int ch : nums) mx = max(mx,ch);
        while(j < n) {
            if(nums[j] == mx) cnt++;
            j++;
            while(i < j and cnt >= k) {
                ans += (n - j + 1);
                if(nums[i] == mx) cnt--;
                i++;
            }
        }
        return ans;
    }
};
