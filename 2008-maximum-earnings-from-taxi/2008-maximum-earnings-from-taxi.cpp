class Solution {
public:
int findIndex(int idx, int lo, int hi, vector<vector<int>>&rides){
    int res = rides.size();
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(rides[mid][0]>=rides[idx][1]){
            res = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return res;
}
long long solve(int idx, int n, vector<vector<int>>&rides,vector<long long>&dp){
    if(idx>=n)return 0;
    if(dp[idx]!=-1)return dp[idx];
    long long skip = solve(idx+1, n, rides, dp);
    int i = idx+1;
    // for(; i<n; i++){
    //     if(rides[i][0]>=rides[idx][1])break;     // converting this to bs
    // }
    // long long take = (rides[idx][1] - rides[idx][0] + rides[idx][2]) + solve(i, rides.size(), rides, dp);
    long long take = (rides[idx][1] - rides[idx][0] + rides[idx][2]) + solve(findIndex(idx, idx+1, rides.size()-1, rides), rides.size(), rides, dp);
    return dp[idx] = max(skip, take);
}
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        // same ye bhi inclusive hai aur classic dp question h 
        // linear search me tle dega aur binary search me accept ho jaega
        vector<long long>dp(rides.size()+1, -1);
        sort(rides.begin(), rides.end()); 
        return solve(0,rides.size(),rides,dp);
    }
};