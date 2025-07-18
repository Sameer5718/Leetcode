class Solution {
public:
bool isValid(vector<int>&arr, int h, int mid){
    double hr = 0;
    int n = arr.size();
    for(int i = 0; i<n; i++){
        hr+=ceil((double)arr[i]/mid);
    }
    return hr<=h;
}
    int minEatingSpeed(vector<int>& p, int h) {
        int n = p.size();
        auto f = p.begin();
        auto l = p.end();
        int lo = 1;//*min_element(f,l);
        int hi = *max_element(f,l);//accumulate(f,l,0);
        int ans = INT_MAX;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isValid(p, h, mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};