class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int i = 1, j = 1e9,ans;
        while(i <= j) {
            int mid = (i+j)/2;
            int possible = 0,last = -2;
            for(int ind = 0; ind < nums.size(); ind++) {
                if(nums[ind] <= mid and ind-1 != last) {
                    possible++;
                    last = ind;
                }
            }
            cout << possible << endl;
            if(possible >= k) {
                ans = mid;
                j = mid-1;
            } else i = mid+1;
        }
        return ans;
    }
};
