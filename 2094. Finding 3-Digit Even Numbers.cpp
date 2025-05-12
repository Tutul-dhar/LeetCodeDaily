class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans,a(10,0);
        for(int ch : digits) a[ch]++;

        for(int i = 1; i <= 9; i++) {
            for(int j = 0; j <= 9; j++) {
                for(int k = 0; k <= 9; k++) {
                    a[i]--;
                    a[j]--;
                    a[k]--;
                    if(a[i] >= 0 and a[j] >= 0 and a[k] >= 0) {
                        int p = i*100 + j*10 + k;
                        if(p%2 == 0) ans.push_back(p);
                    }
                    a[i]++;
                    a[j]++;
                    a[k]++;
                }
            }
        }
        return ans;
    }
};
