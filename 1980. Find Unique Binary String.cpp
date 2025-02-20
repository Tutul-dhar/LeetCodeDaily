class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";

        int i =0,j = 0,n = nums.size();
        while(i < n) {
            if(nums[i][j] == '1') ans += '0';
            else ans += '1';
            i++;
            j++;
        }

        return ans;
    }
};
