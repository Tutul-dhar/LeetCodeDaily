class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int ch : nums) {
            int p = ch,q = 0;
            while(p) {
                q++; p/=10;
            }
            if(q%2 == 0) ans++;
        }
        return ans; 
    }
};
