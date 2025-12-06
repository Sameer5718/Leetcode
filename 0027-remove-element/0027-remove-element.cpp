class Solution {
public:
void show(vector<int>n){
    for(int i: n)cout<<i<<" ";
    cout<<endl;
    return;
}
    int removeElement(vector<int>& nums, int val) {
        int freq = 0;
        for(int i = 0; i<nums.size(); i++){
            //cout<<"i= "<<i<<" e ";
            if(nums[i]==val){
                // cout<<freq<<" "<<nums[i]<<" "<<endl;
                nums.erase(nums.begin()+i);
                i--;
            }
            else freq++;
            // show(nums);
        }
        return freq;
    }
};