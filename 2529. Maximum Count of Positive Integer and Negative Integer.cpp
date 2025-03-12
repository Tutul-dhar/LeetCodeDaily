class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0,neg = 0;
        for(int ch : nums) {
            if(ch > 0 ) pos++;
            else if(ch < 0) neg++;
        }
        return max(pos,neg);
    }
};
