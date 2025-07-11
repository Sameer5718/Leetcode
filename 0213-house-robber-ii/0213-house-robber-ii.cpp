class Solution {
public:
int solve(int idx, int n, vector<int>&nums, vector<int>&dp){
    if(idx>n)return 0;
    if(dp[idx]!=-1)return dp[idx];
    int skip = solve(idx+1, n, nums,dp);
    int take = nums[idx]+solve(idx+2, n, nums,dp);
    // cout<<skip<<" "<<take<<" "<<n<<endl;
    return dp[idx] = max(skip, take);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n+1, -1);
        int a1 = solve(0,n-2,nums, dp);
        fill(dp.begin(), dp.end(),-1);
        int a2 = solve(1,n-1,nums, dp);
        return max(a1, a2);
    }
};