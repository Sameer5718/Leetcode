class Solution {
public:
vector<vector<int>>mem;
int search(int idx, int lo, int hi, vector<vector<int>>& ev){
    int res = ev.size();
    int et = ev[idx][1];
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(ev[mid][0] > ev[idx][1]){
            res = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return res;
}
int solve(int i, int k, vector<vector<int>>& ev){
    int j = i+1;
    if(i>=ev.size() || k<=0)return 0;
    if(mem[i][k]!=-1)return mem[i][k];
    int start = ev[i][0];
    int end = ev[i][1];
    int val = ev[i][2];
    int skip = solve(i+1, k, ev);
    int take = 0;
    /*
    for(j = i+1; j<ev.size(); j++){
        if(ev[j][0]>ev[i][1])break;
    }
    */
    // binary search
    j = search(i, i+1, ev.size()-1, ev);
    take = val + solve(j, k-1, ev);
    return mem[i][k] = max(skip, take);
}
    int maxValue(vector<vector<int>>& ev, int k) {
        sort(ev.begin(), ev.end());
        int n = ev.size();
        mem.resize(n+1, vector<int>(k+1,-1));
        return solve(0, k, ev);
    }
};