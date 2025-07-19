class Solution {
public:
bool isValid(vector<int>&arr, int mid, int k){
    int n = arr.size();
    int lp = arr[0];
    int c = 1;
    for(int i = 1; i<n; i++){
        if(arr[i]+lp<=mid){
            lp+=arr[i];
        }
        else {
            lp = arr[i];
            c++;
        }
    }
    return c<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        auto f = nums.begin();
        auto l = nums.end();
        int lo = *max_element(f,l);
        int hi = accumulate(f,l,0);
        int ans = 0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isValid(nums, mid, k)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};