class Solution {
public:
int solve(int n, vector<int>cost, int m, int i, int sum, vector<int>&dp){
    if(i==n)return 0;
    else if(i>n)return 0;
   // if(i<n)sum+=cost[i];
    if(dp[i]!=-1)return dp[i];
    return dp[i] = cost[i] + min(solve(n, cost, m, i+1, sum, dp), solve(n, cost, m, i+2, sum, dp));
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int m = INT_MAX;
        vector<int>dp(n+1, -1);
        return min(solve(n, cost, m, 0, 0, dp), solve(n, cost, m, 1, 0, dp));
    }
};