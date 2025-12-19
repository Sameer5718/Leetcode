class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>map;
        string t,r,b;
        int n = strs.size();
        for(int i = 0; i<n; i++){
            t = strs[i];
            sort(t.begin(), t.end());
            auto it = map.find(t);
            if(it==map.end()){
                map[t].push_back(strs[i]);
            }
            else{
                map[t].push_back(strs[i]);
            }
        }

        auto it = map.begin();
        vector<vector<string>>res;
        while(it!=map.end()){
            res.push_back(it->second);
            it++;
        }
        return res;
    }
};