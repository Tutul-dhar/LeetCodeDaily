class Solution {
public:
    const int mod = 1000000007;
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0,zero = 1,one = 0,sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            sum %= 2;
            if(sum == 1) {
                one++; 
                ans += zero;
            } else {
                zero++;
                ans += one;
            }
            ans %= mod;
        }
        return ans;
    }
};
