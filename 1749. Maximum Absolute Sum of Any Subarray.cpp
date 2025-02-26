class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0,pos = 0,neg = 0;
        for(int ch : nums) {
            pos += ch;
            neg += (-1)*ch;

            ans = max(ans,pos);
            ans = max(ans,neg);
            pos = max(0,pos);
            neg = max(0,neg);
        }
        return ans;
    }
};
