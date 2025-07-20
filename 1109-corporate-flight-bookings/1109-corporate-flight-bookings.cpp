class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bk, int n) {
        // difference array!!
        vector<int>res(n,0);
        int m = bk.size();
        for(int i = 0; i<m; i++){
            res[bk[i][0]-1]+=bk[i][2];
            if((bk[i][1])<n)
                res[bk[i][1]]+=(bk[i][2])*-1;
        }
        // for(int i : res)cout<<i<<" ";
        vector<int>prefix(n);
        prefix[0]=res[0];
        for(int i = 1; i<n; i++){
            prefix[i]=prefix[i-1]+res[i];
        }
        // for(int i : prefix)cout<<i<<" ";
        return prefix;
    }
};