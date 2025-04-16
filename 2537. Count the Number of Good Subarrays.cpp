class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;

        unordered_map<int,int> ma;
        int i = 0,j = 0,n = nums.size();
        long long pos = 0;
        while(j < n) {
            long long p = ma[nums[j]];
            pos -= (p*(p-1))>>1ll;
            ma[nums[j]]++;
            j++;
            p++;
            pos += (p*(p-1))>>1ll;
            while(pos >= k and i < j) {
                ans += (n - j + 1);
                p = ma[nums[i]];
                pos -= (p*(p-1))>>1ll;
                ma[nums[i]]--;
                p--;
                pos += (p*(p-1))>>1ll;
                i++;
            }
        }

        return ans;
    }
};
