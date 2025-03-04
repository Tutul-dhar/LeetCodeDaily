class Solution {
public:
    bool checkPowersOfThree(int n) {
        int p = 1;
        while(p*3 <= n) {
            p *= 3;
        }
        while(n) {
            if(n >= p) n -= p;
            if(n >= p) return false;
            p /= 3; 
        }
        return true;
    }
};

--------------------------------------------------

class Solution {
public:
    bool checkPowersOfThree(int n) {
        for(int i = 0; i < (1<<17); i++) {
            int e = 0,p = 1;
            for(int j = 0; j < 17; j++) {
                if(((i>>j) & 1)) e += p;
                p *= 3;
            }

            if(e == n) return true;
        }
        return false;
    }
};
