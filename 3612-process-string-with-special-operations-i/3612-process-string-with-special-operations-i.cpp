class Solution {
public:
    string processStr(string s) {
        string res;
        for(int i = 0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z')res+=s[i];
            else if(!res.empty() && s[i]=='*')res.erase(res.begin()+res.size()-1);
            else if(!res.empty() &&s[i]=='#')res+=res;
            else if(!res.empty() &&s[i]=='%')reverse(res.begin(),res.end());
            //cout<<res<<" ";
        }
        return res;
    }
};