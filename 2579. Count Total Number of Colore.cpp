class Solution {
public:
    long long coloredCells(int n) {
        
        long long p = (n*1ll*(n-1))/2ll;
        p *= 4ll;

        p++;
        return p;
    }
};
