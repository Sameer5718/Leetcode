class Solution {
public:
bool isValid(vector<int>&arr, int mid, int days){
    int n = arr.size();
    int day = 1;
    int wt = arr[0];
    for(int i = 1; i<n ; i++){
        if(wt+arr[i]<=mid){
            wt+=arr[i];
        }
        else{
            day++;
            wt=arr[i];
        }
    }
    return day<=days;
}
    int shipWithinDays(vector<int>& ship, int days) {
        //sort(ship.begin(), ship.end());
        auto f = ship.begin();
        auto l = ship.end();
        int hi = accumulate(f,l,0);
        int n = ship.size();
        int lo = *max_element(f,l);
        int ans = INT_MAX;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isValid(ship, mid, days)){
                ans = min(ans,mid);
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};