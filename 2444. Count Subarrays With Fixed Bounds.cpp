class Solution {
public:
    int seg_mx[400100],seg_mn[400100];
    void build(int ind,int ss,int se, vector<int> &a) {
        if(ss == se) {
            seg_mx[ind] = a[ss-1];
            seg_mn[ind] = a[ss-1];
            return;
        }
        int mid = (ss + se)>>1;
        build(2*ind,ss,mid,a);
        build(2*ind+1,mid+1,se,a);
        seg_mx[ind] = max(seg_mx[2*ind],seg_mx[2*ind+1]);
        seg_mn[ind] = min(seg_mn[2*ind],seg_mn[2*ind+1]);
    }

    int query_mx(int ind,int ss,int se,int l,int r) {
        if(ss > r or se < l) return 0;
        if(ss >= l and se <= r) return seg_mx[ind];
        int mid = (ss+se)>>1;
        return max(query_mx(2*ind,ss,mid,l,r),query_mx(2*ind+1,mid+1,se,l,r));
    }

    int query_mn(int ind,int ss,int se,int l,int r) {
        if(ss > r or se < l) return 1e9;
        if(ss >= l and se <= r) return seg_mn[ind];
        int mid = (ss+se)>>1;
        return min(query_mn(2*ind,ss,mid,l,r),query_mn(2*ind+1,mid+1,se,l,r));
    }

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        build(1,1,n,nums);
        long long ans = 0;
        vector<int> mnn,mxx;
        for(int i = 0; i < n; i++) {
            if(nums[i] == minK) mnn.push_back(i+1);
            if(nums[i] == maxK) mxx.push_back(i+1);
        }
        reverse(mnn.begin(),mnn.end());
        reverse(mxx.begin(),mxx.end());
        for(int i = 0; i < n; i++) {
            if(mnn.size() == 0 or mxx.size() == 0) break;
            int fmx=mxx.back(),lmx = -1,fmn =mnn.back(),lmn = -1;
            if(fmx == i+1) mxx.pop_back();
            if(fmn == i+1) mnn.pop_back();
            int p = query_mx(1,1,n,i+1,fmx);
            if(p > maxK) continue;
            p = query_mn(1,1,n,i+1,fmn);
            if(p < minK) continue;
            
            
            int l = fmx,r = n;
            while(l <= r) {
                int mid = (l + r)>>1;
                int p = query_mx(1,1,n,fmx,mid);
                if(p > maxK) r = mid-1;
                else if(p < maxK) l = mid+1;
                else {
                    lmx = mid;
                    l = mid+1;
                }
            }

            
            l = fmn,r = n;
            while(l <= r) {
                int mid = (l + r)>>1;
                int p = query_mn(1,1,n,fmn,mid);
                if(p < minK) r = mid-1;
                else if(p > minK) l = mid+1;
                else {
                    lmn = mid;
                    l = mid+1;
                }
            }
            fmx = max(fmx,fmn);
            lmx = min(lmn,lmx);
            //cout << lmx << ' ' << fmx << endl;
            ans += max(0,(lmx - fmx + 1));
        }
        return ans;
    }
};
