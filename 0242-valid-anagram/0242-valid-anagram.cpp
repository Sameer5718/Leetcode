class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())return 0;
        map<char,int>m1;
        map<char,int>m2;
        for(int i = 0; i<s.size(); i++){
            m1[s[i]]++;
        }
        for(int i = 0; i<t.size(); i++){
            m2[t[i]]++;
        }
        auto it = m1.begin();
        auto it2= m2.begin();
        while(it!=m1.end() || it2!=m2.end()){
            if(it->first != it2->first || it->second != it2->second)return 0;
            it++;
            it2++;
        }
        return 1;
    }
};