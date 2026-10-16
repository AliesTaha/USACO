class Solution {
public:
    int count=0;
    vector<int> vert;
    vector<int> diagn;
    vector<int> diags;

    void bt(int row, int cols){
        cout<<"got called"<<endl;
        if (row==cols){
            count++;
            return;
        }
        for (int y=0; y<cols; y++){
            cout<<cols<<":"<<y<<row<<endl;
            cout<<y<<row+y<<row-y+cols-1<<endl;
            cout<<(vert[y]||diagn[row+y]||diags[row-y+cols-1])<<endl;
            cout<<"-"<<endl;
            if (vert[y]||diagn[row+y]||diags[row-y+cols-1]) continue;
            vert[y]=diagn[row+y]=diags[row-y+cols-1]=1;
            bt(row+1, cols);
            vert[y]=diagn[row+y]=diags[row-y+cols-1]=0;
        }
    }

    int totalNQueens(int n) {
        vert.resize(n);
        diagn.resize(2*n);
        diags.resize(2*n);
        bt(0, n);
        return count;
        // let n be the number of rows (x axis)
        // let us go through each row
        // mark diagn (x+y) and diags (n-1+x-y) and vert (y) as marked
        // move to next row 
        // unmark

    }
};