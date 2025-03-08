class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = blocks.size(),b = 0,w = 0;
        for(int i = 0; i < blocks.size(); i++) {
            if(blocks[i] == 'B') b++;
            else w++;
            if(i-k >= 0) {
                if(blocks[i-k] == 'B') b--;
                else w--;
            }
            if(i >= k-1) {
                ans = min(ans,w);
            }
        }
        return ans;
    }
};
