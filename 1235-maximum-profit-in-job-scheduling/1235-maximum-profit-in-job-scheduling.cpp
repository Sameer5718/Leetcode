class Solution {
public:
int getNextIndex(int idx, int lo, int hi, vector<vector<int>>&ev, int n){
    int st = ev[idx][1];
    int et = ev[hi][0];
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(ev[mid][0]>=st){
            n = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return n;
}
int solve(int idx, int n, vector<vector<int>>&ev, vector<int>&dp){
    if(idx>=n)return 0;
    if(dp[idx]!=-1)return dp[idx];
    int skip = solve(idx+1, n, ev, dp);
    int i = idx+1;
    /*
    for(; i<n; i++){
        if(ev[i][0]>=ev[idx][1])break;  changing this to bs coz this gives tle
    }
    */
    int take = ev[idx][2] + solve(getNextIndex(idx, idx+1, ev.size()-1, ev, n), n, ev, dp);
    return dp[idx] = max(take, skip);
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // create a combined vector from given inp
        // find next job using bs
        // either take or skip
        // CLASSIC DP
        vector<vector<int>>ev;
        for(int i = 0; i<startTime.size(); i++){
            ev.push_back({startTime[i],endTime[i], profit[i]});
        }
        sort(ev.begin(), ev.end());
        int n = ev.size();
        vector<int>dp(n+1,-1);
        return solve(0, n, ev, dp);
    }
};