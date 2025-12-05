class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string>copy;
        copy = strs;
        // for(int i = 0; i<n; i++){
        //     sort(copy[i].begin(), copy[i].end());
        // }
        vector<vector<string>>res;
        vector<string>temp;
        for(int i = 0; i<n; i++){
            if(copy[i].size()>0)
                sort(copy[i].begin(), copy[i].end());
            string t = copy[i];
            if(t!="1" /* && t != "" */){
                temp.push_back(strs[i]);
                for(int j = i+1; j<n; j++){
                    if(copy[j].size()>0)
                        sort(copy[j].begin(), copy[j].end());
                    string r = copy[j];
                    if(r==t){
                        temp.push_back(strs[j]);
                        copy[j]="1";
                    }
                    else continue;
                }
                res.push_back(temp);
                temp.clear();
            }
            else
                continue;
        }
        return res;
    }
};