class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> vis(501,0);
        int n = nums.size();
        for(int ch : nums) {
            if(vis[ch]) {
                vis[ch] = 0;
                n -= 2;
            } else vis[ch] = 1;
        }
        return n == 0;
    }
};
