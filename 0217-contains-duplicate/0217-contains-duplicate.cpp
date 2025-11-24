class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // int psize = abs(*max_element(nums.begin(), nums.end()));
        // int nsize = abs(*min_element(nums.begin(), nums.end()));
        // vector<long>pvis(psize+1, 0);
        // vector<long>nvis(nsize+1, 0);
        map<int,int>m;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            /*
            if(nums[i]>=0 && pvis[nums[i]]!=0){
                return 1;
            }
            else if(nums[i]>=0 && pvis[nums[i]]==0){
                pvis[nums[i]]=1;
            }
            else if(nums[i] < 0 && nvis[abs(nums[i])] != 0){
                return 1;
            }
            else{
                nvis[abs(nums[i])]=1;
            }
            */
            m[nums[i]]++;
        }
        auto it = m.begin();
        while(it!=m.end()){
            if(it->second>1)return 1;
            it++;
        }
        return 0;
    }
};