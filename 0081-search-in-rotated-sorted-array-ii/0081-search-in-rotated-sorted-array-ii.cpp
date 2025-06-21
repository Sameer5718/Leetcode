class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target)return 1;
            if(nums[lo]==nums[mid] && nums[mid]==nums[hi]){
                lo++;
                hi--;
                continue;
                // if(lo>=n || hi<0)return 0;
            }
            if(nums[mid]>=nums[lo]){
                if(target>=nums[lo] && target<=nums[mid]){
                    hi = mid;
                }
                else lo = mid+1;
            }
            else if(nums[mid]<=nums[hi]){
                if(target>=nums[mid] && target<=nums[hi]){
                    lo= mid+1;
                }
                else hi = mid;
            }
        }
        return 0;
    }
};