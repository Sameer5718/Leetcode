class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // find (uses iterator) is used when we want to retrieve or update the desired info in the map
        // count is used only to check if that val exists or not, it returns bool
        map<int, int>m;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            auto it = m.find((target-nums[i]));
                if(it!=m.end()){
                    return {i,it->second};
                }
                else{
                    m[nums[i]] = i;
                }
            }
            return{-1,-1};
        }
    
};