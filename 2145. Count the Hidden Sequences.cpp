class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int i = lower, j = upper;
        int left = -1e9,right = -1,n = differences.size();
        while(i <= j) {
            int mid = (i + j)>>1;
            bool less = false,greater = false;
            int val = mid;
            for(int k = 0; k < n; k++) {
                val += differences[k];
                if(val < lower) {
                    less = true;
                    break;
                } else if(val > upper) {
                    greater = true;
                    break;
                }
            }
            if(less) i = mid+1;
            else if(greater) j = mid-1;
            else {
                left = mid;
                j = mid-1;
            }
        }
        if(left == -1e9) return 0;

        
        i = lower, j = upper;
        while(i <= j) {
            int mid = (i + j)>>1;
            bool less = false,greater = false;
            int val = mid;
            for(int k = 0; k < n; k++) {
                val += differences[k];
                if(val < lower) {
                    less = true;
                    break;
                } else if(val > upper) {
                    greater = true;
                    break;
                }
            }
            if(less) i = mid+1;
            else if(greater) j = mid-1;
            else {
                right = mid;
                i = mid+1;
            }
        }
        return right - left+1;
    }
};
