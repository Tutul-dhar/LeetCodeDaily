#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class Solution {
private:
    typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> left(n,0),right(n,0),pos(n,0);
        for(int i = 0; i < n; i++) pos[nums2[i]] = i;
        int p = 0;
        ordered_set s;
        for(int i = 0; i < n; i++) {
            int e = pos[nums1[i]];
            s.insert(e);
            int p = s.order_of_key(e);
            left[i] = p;
        }

        p = 0;
        s.clear();
        for(int i = n-1; i >= 0; i--) {
            int e = pos[nums1[i]];
            e = n-e-1;
            s.insert(e);
            int p = s.order_of_key(e);
            right[i] = p;
        }

        long long ans = 0;
        for(int i = 1; i < n-1; i++) {
            long long l = left[i],r = right[i];
            ans += l*r;
        }
        return ans;
    }
};
