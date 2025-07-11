class Solution {
public:
int solve(vector<int>&nums, int hno){
    if(hno>=nums.size())return 0;
    int skip = solve(nums, hno+1);
    int take = nums[hno]+solve(nums,hno+2);
    return max(skip, take);    
}
    int rob(vector<int>& nums) {
        return solve(nums,0);
        // return max(solve(nums, 0), solve(nums,1));
    }
};