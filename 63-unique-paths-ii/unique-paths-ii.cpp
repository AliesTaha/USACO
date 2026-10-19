class Solution {
public:
    int dp(vector<vector<int>>& obstacleGrid, vector<vector<int>>& vGrid, int x, int y, int m, int n, int count){
        if ((x==m-1) && (y==n-1)){
            count++;
            return count;
        }
        if (vGrid[x][y]!=-1){
            return vGrid[x][y];
        }
        int right, bottom;
        right=bottom=0;
        //go right
        if (y<n-1 && obstacleGrid[x][y+1]==0) right=dp(obstacleGrid, vGrid, x, y+1, m,n, count);
        //go bottom
        if (x<m-1 && obstacleGrid[x+1][y]==0) bottom=dp(obstacleGrid, vGrid, x+1, y, m,n, count);
        vGrid[x][y]=right+bottom;
        return vGrid[x][y];

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]==1){
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> vGrid(m, vector<int>(n, -1));
        return dp(obstacleGrid, vGrid, 0,0,m,n, 0);
    }
};