class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long i = 0, j = 1e14,ans=0;
        while(i <= j) {
            long long mid = (i+j)/2ll;
            long long p = 0;
            for(int k = 0; k < ranks.size(); k++) {
                long long c = mid / (long long) ranks[k];
                c = sqrt(c);
                p += c;
                if(p >= cars) break;
            }
            if(p >= cars) {
                ans = mid;
                j = mid-1;
            } else i = mid+1;
        }
        return ans;
    }
};
