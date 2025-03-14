class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int i = 1, j = 1e7,res = 0;
        while(i <= j) {
            int mid = (i+j)/2;
            long long ans = 0;
            for(int ch : candies) {
                ans = ans + (long long)(ch/mid);
            }
            if(ans >= k) {
                res = mid;
                i = mid+1;
            } else j = mid-1; 
        }
        return res;
    }
};
