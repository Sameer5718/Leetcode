class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int x = 0;
        for(string s: op){
            if(s[0]=='+' || s[2] == '+'){
                x++;
            }
            else x--;
        }
        return x;
    }
};