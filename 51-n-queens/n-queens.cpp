#define pb push_back 
class Solution {
public:
    vector<int> col;
    vector<int> du;
    vector<int> dd;
    vector<int> vy;
    vector<vector<int>> ret;
    void recurs(int row, int cols, vector<int> xy){
        if (row==cols){
            ret.push_back(vy);
            return;
        }
        else{
            for (int c=0; c<cols; c++){
                if (col[c]||du[row+c]||dd[row-c+cols-1]) continue;
                col[c]=du[row+c]=dd[row-c+cols-1]=1;
                vy.pb(c);
                recurs(row+1, cols, vy);
                vy.pop_back();
                col[c]=du[row+c]=dd[row-c+cols-1]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        col.resize(n);    
        du.resize(2*n);    
        dd.resize(2*n);    
        recurs(0, n, vy);
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
            string tb(n, '.');
            for (auto y: ret[i]){
                tb[y]='Q';
                soln.pb(tb);
                tb[y]='.'; 
            }
            sol.pb(soln);
        }
        return sol;

    }
};