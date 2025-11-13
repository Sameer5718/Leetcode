class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>res;
        int n = words.size();
        int counter = 0;
        for(string w: words){
            int idx = w.find(x);
            if(idx!=string::npos){
                res.push_back(counter);
            }
            counter++;
        }
        return res;
    }
};