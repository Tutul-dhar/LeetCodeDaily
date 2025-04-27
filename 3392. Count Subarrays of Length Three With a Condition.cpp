class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 1; i < n-1; i++) {
            int e = nums[i-1] + nums[i+1];
            if(nums[i]%2 == 0 and (nums[i]/2) == e) ans++;
        }
        return ans;
    }
};
