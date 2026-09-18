class Solution {
public:
    vector<vector<int>> diff={{1,0},{0,1},{0,-1},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if(grid[0][0]==1 || grid[r-1][c-1]==1) return -1;
        vector<int> arr;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        visited[0][0]=true;
        q.push({{0,0},1});
        while(!q.empty()){
            auto[idx,len]=q.front();q.pop();
            auto[ir,ic]=idx;
            if(ir==r-1 && ic==c-1) return len;
            for(int i=0;i<8;i++){
                int ar=ir+diff[i][0];
                int ac=ic+diff[i][1];
                
                if(ar>=0 && ac>=0 && ar<r && ac<c && grid[ar][ac]==0 && !visited[ar][ac]){
                    q.push({{ar,ac},len+1});
                    visited[ar][ac]=true;
                }
            }
        }
        return -1;
    }
};