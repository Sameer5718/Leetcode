class Solution {
public:
int bsch(vector<int>&wt, int mid){
    int days = 1;
    int load = 0;
    for(int i = 0; i<wt.size(); i++){
        if(load+wt[i]>mid){
            days++;
            load = 0;
            load+=wt[i];
        }
        else{
            load+=wt[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& wt, int days) {
        
        int n = wt.size();
        vector<int>prefix(n,0);
        prefix[0]=wt[0];
        for(int i = 1; i<n; i++){
            prefix[i] = (wt[i]+prefix[i-1]);
        }
        int lo = *max_element(wt.begin(),wt.end()); 
        int hi = prefix.back();
        int m = INT_MAX;
        int ans = INT_MAX;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(days>=bsch(wt,mid)){
                ans = min(ans,mid);
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};