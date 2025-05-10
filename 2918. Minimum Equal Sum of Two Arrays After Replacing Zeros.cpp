class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long a = 0,b = 0,sum1 = 0,sum2 = 0;
        for(int ch : nums1) {
            if(ch == 0) a++;
            sum1 += ch;

        }

        for(int ch : nums2) {
            if(ch == 0) b++;
            sum2 += ch;
            
        }

        if(a == 0 and b == 0) {
            if(sum1 != sum2) return -1;
        } else if(a == 0 and sum1 < sum2+b) return -1;
        else if(b == 0 and sum1+a > sum2) return -1;
        sum1 += a;
        sum2 += b;
        return max(sum1,sum2);
    }
};
