
using namespace std;

class Solution {
    public:
        int dp(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& gv, int curr_sum){
            //given x and y, i can either move to the right or down unless i'm at edge
            if (gv[x][y]!=-1){
                return gv[x][y];
            }
            if (x==m-1 && y==n-1){
                gv[x][y]=grid[x][y];
                return gv[x][y];
            }
            int bottom_path, right_path;
            bottom_path=right_path='INF';
            if (x!=m-1){
                bottom_path=dp(x+1,y,m,n,grid,gv,curr_sum);
            }
            if (y!=n-1)
            {
                right_path=dp(x,y+1,m,n,grid,gv,curr_sum);
            }
            gv[x][y]=grid[x][y]+min(bottom_path, right_path);
            cout<<"x: "<<x<<" y: "<<y<< " bottom_path: " <<bottom_path<<" right_path: "<<right_path<<" gv[x][y]: "<<gv[x][y]<<endl;
            return gv[x][y];
        }
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
            int n= grid[0].size();
            vector<vector<int>> gv(m, vector<int>(n, -1));
            return dp(0,0,m,n,grid,gv, 0);
        }
    };