class Solution {
public:
bool isValid(vector<int>&dist, double hour, int s){
    double sum = 0.0;
    int n = dist.size();
    for(int i = 0; i<n-1; i++){
        sum+=ceil((double(dist[i])/s));
    }
    sum+=((double)dist[n-1]/s);
    return sum<=hour;
}
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int lo = 1;
        int hi = 1e7;
        int ans = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isValid(dist, hour, mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};