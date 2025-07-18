class Solution {
public:
bool isValid(vector<int>&fl, int mid, int m, int k){
    int c = 0, n = fl.size(), bq = 0;
    for(int i = 0; i<n; i++){
        if(c>=k){
            bq++;
            c=0;
        }
        if(fl[i]<=mid)c++;
        else c=0;
    }
    if(c>=k)bq++;
    return bq>=m;
}
    int minDays(vector<int>& fl, int m, int k) {
        int n = fl.size();
        auto f = fl.begin();
        auto l = fl.end();
        int lo = *min_element(f,l);
        int hi = *max_element(f,l);
        int ans = INT_MIN;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isValid(fl, mid, m, k)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans==INT_MIN?-1:ans;
    }
};