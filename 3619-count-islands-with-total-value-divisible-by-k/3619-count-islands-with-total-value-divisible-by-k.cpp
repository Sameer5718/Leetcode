class Solution {
public:
bool bfs(int k, vector<vector<int>>&grid, vector<vector<int>>&vis, queue<pair<pair<int,int>,int>>&q, int n, int m){
    int res = 0;
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int r = front.first.first;
        int c = front.first.second;
        long long cursum = front.second;
        vis[r][c]=1;
        vector<int>dr = {0,1,0,-1};
        vector<int>dc = {-1,0,1,0};
        for(int i = 0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<n && nc<m && nr>=0 && nc>=0 && vis[nr][nc]==0 && grid[nr][nc]!=0){
                q.push({{nr,nc}, grid[nr][nc]});
                vis[nr][nc]=1;
            }
        }
        res += cursum;
    }
    return res%k==0;
}
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;  //store {cell's val and curr sum}
        vector<vector<int>>vis(n, vector<int>(m,0));
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]!=0 && vis[i][j]==0){
                    q.push({{i,j},grid[i][j]});
                    if(bfs(k, grid, vis, q, n, m))count++;
                }
            }
        }
        return count;
    }
};