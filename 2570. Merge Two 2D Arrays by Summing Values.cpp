class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0,j = 0,n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        while(i < n and j < m) {
            if(nums1[i][0] == nums2[j][0]) {
                ans.push_back({nums1[i][0], nums1[i][1]+nums2[j][1]});
                i++;
                j++;
            } else if(nums1[i][0] < nums2[j][0]) {
                ans.push_back({nums1[i][0], nums1[i][1]});
                i++;
            } else {
                ans.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }
        while(i < n) {
            ans.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }

        while(j < m) {
            ans.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }
        return ans;
    }
};
