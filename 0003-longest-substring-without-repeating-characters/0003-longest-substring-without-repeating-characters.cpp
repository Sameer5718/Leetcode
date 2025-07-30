class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int counter=0;
        int begin=0;
        int end=0;
        int d=0;
        vector<int>map(128,0);
        while(end<s.size()){
            if(map[s[end++]]++>0)counter++;
            while(counter>0){
                if(map[s[begin++]]-- >1){
                    counter--;
                }
            }
            d=max(d,end-begin);
        }
        return d;
    }
};