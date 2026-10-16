#define pb push_back 
class Solution {
public:
    vector<int> col;
    vector<int> du;
    vector<int> dd;
    vector<vector<int>> xy;
    vector<vector<vector<int>>> ret;
    void recurs(int row, int cols, vector<vector<int>> xy){
        if (row==cols){
            ret.push_back(xy);
            return;
        }
        else{
            for (int c=0; c<cols; c++){
                if (col[c]||du[row+c]||dd[row-c+cols-1]) continue;
                col[c]=du[row+c]=dd[row-c+cols-1]=1;
                xy.pb({row, c});
                recurs(row+1, cols, xy);
                xy.pop_back();
                col[c]=du[row+c]=dd[row-c+cols-1]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        col.resize(n);    
        du.resize(2*n);    
        dd.resize(2*n);    
        recurs(0, n, xy);
        cout<<"yo"<<endl;
        // for (auto re: ret){
        //     for (auto vec:re){
        //         for (auto v: vec){
        //             cout<<v<<",";
        //         }
        //         cout<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<vector<string>> sol;
        for (int i=0; i<ret.size();i++){
            vector<string> soln;
            vector<vector<int>> curr=ret[i];
            for (auto vec: curr){
                int y=vec[1];
                string prfx(y, '.');
                string sfx(n-y-1, '.');
                string fin=prfx+"Q"+sfx;
                soln.pb(fin); 
            }
            sol.pb(soln);
        }
        return sol;

    }
};