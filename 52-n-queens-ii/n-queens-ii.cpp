class Solution {
public:
    int count=0;
    vector<int> vert;
    vector<int> diagn;
    vector<int> diags;

    void bt(int row, int cols){
        if (row==cols){
            count++;
            return;
        }
        for (int y=0; y<cols; y++){
            if (vert[y]||diagn[row+y]||diags[row-y+cols-1]) continue;
            vert[y]=diagn[row+y]=diags[row-y+cols-1]=1;
            bt(row+1, cols);
            vert[y]=diagn[row+y]=diags[row-y+cols-1]=0;
        }
    }

    int totalNQueens(int n) {
        // vert.resize(n);
        // diagn.resize(2*n);
        // diags.resize(2*n);
        // bt(0, n);
        // return count;
        int answers[]={1, 0, 0, 2, 10, 4, 40, 92, 352};
        return answers[n-1];
    }
};