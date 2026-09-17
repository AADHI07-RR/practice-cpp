class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int color) {
        int r=arr.size();
        int c=arr[0].size();
        vector<vector<int>> diff={{0,-1},{-1,0},{0,1},{1,0}};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int og=arr[sr][sc];
        if(og==color) return arr;
        arr[sr][sc]=color;
        while(!q.empty()){
            auto[R,C]=q.front();q.pop();
            for(int i=0;i<4;i++){
                int ar=R+diff[i][0];
                int ac=C+diff[i][1];
                if(ar>=0 && ac>=0 && ar<r && ac<c && arr[ar][ac]==og){
                    arr[ar][ac]=color;
                    q.push({ar,ac});
                }
            }
        }
    return arr;  
    }
    
};