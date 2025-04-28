class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> a(n);
        a[0] = nums[0];
        for(int i = 1; i < n; i++) {
            a[i] = nums[i];
            a[i] += a[i-1];
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long left = 0;
            if(i) left = a[i-1];
            int l = i,r = n-1,q = i-1;
            while(l <= r) {
                int mid = (l + r)>>1;
                long long right = a[mid];
                right -= left;
                right = (right * (long long)(mid-i+1));
                if(right < k) {
                    q = mid;
                    l = mid+1;
                } else r = mid-1;
            }
            ans += (q-i+1);
        }
        return ans;
    }
};
