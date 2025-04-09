class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int ch : nums) {
            if(ch < k) return -1;
            if(ch > k) s.insert(ch);
        }
        return s.size();
    }
};
