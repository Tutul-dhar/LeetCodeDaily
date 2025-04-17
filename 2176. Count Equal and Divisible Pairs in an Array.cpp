class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0,n = nums.size();
        //(i*j)%k == ((i%k) * (j%k))%k 
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] == nums[j] and (i*j)%k == 0) ans++;
            }
        }
        return ans;
    }
};
