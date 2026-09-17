class Solution {
public:
    vector<vector<int>> diff={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<char>>& arr,int row,int col,int R,int C){
        arr[row][col]='0';
        for(int i=0;i<4;i++){
            int ar=row+diff[i][0];
            int ac=col+diff[i][1];
            if(ar>=0 && ar<R && ac>=0 && ac<C && arr[ar][ac]=='1'){
                dfs(arr,ar,ac,R,C);
            }
        }        
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j,r,c);
                }
            }
        }
        return count;

    }
};