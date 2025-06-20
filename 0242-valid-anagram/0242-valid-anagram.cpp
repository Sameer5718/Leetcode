class Solution {
public:
    bool isAnagram(string s, string t) {
        // create 2 maps to store the freq of each char and check 
        map<char,int>m1;
        map<char,int>m2;
        int n = s.size();
        int m = t.size();
        if(n!=m)return 0;
        for(int i = 0; i<n; i++){
            m1[s[i]]++;
        }
        for(int i = 0; i < m; i++){
            m2[t[i]]++;
        }
        auto it = m1.begin();
        while(it!=m1.end()){
            if(m2.find(it->first) != m2.end() && m2[it->first] != it->second){
                return 0;
            }
            else if(m2.find(it->first) == m2.end())return 0;
            it++;
        }
        return 1;
    }
};