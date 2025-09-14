class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // find karo target-ar[i] map me hai ki nahi
        // agar nhi h to map me ar[i] -> idx daal do 
        // aur agar h to {map[ar[i]], i} return kardo
        map<int,int>m;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(m.find(target-nums[i])!=m.end() && i != m[target - nums[i]]){
                return {m[target - nums[i]], i};
            }
            else{
                m[nums[i]] = i;
            }
        }
        return {0,0}; 
    }
};