class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        // find free times
        /* for 1 shift 2 free times (gaps) combine
        for 2 shifts 3 gaps combine 
        for k shifts k+1 gaps combine
        hence for k shifts run a window of k+1 size on the freetimes arr and find the max sum
        a.k.a slidin window
        */
        // creating a combined vector
        vector<vector<int>>ev;
        for(int i = 0; i<startTime.size(); i++){
            ev.push_back({startTime[i], endTime[i]});
        }
        vector<int>gaps;
       // if(ev[0][0]!=0){
            gaps.push_back(ev[0][0]);
       // }
       // else gaps.push_back(0);
        for(int i = 1; i<ev.size(); i++){
            gaps.push_back(ev[i][0]-ev[i-1][1]);
        }
        if(ev[ev.size()-1][1]<eventTime)gaps.push_back(eventTime-ev[ev.size()-1][1]);
        
        // run a k+1 size window over gaps
        int m = INT_MIN;
        int i = 0;
        int j = 0;
        int sum = 0;
        int n = gaps.size();
        int cursum = 0;
        while(j<n){
            cursum+=gaps[j];
            if(i<n && j-i+1 > k+1){
                cursum-=gaps[i];
                i++;
            }
            sum = max(sum, cursum);
            j++;
        } 
        return sum;
        // while(i<gaps.size()){
        //     int count = 0;
        //     int sum = 0;
        //     int j = i;
        //     int ans = 0;
        //     while(count<k+1 && j<gaps.size()){
        //         sum+=gaps[j];
        //         ans=max(ans,sum);
        //         count++;
        //         j++;
        //     }
        //     //i%=k;
        //     i++;
        //     m = max(m, ans);
        // }
        // return m==INT_MIN ? 0 : m;
    }
};