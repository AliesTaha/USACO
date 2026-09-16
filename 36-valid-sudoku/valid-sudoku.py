class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        #check the rows
        for i in range(len(board)):
            c_row=board[i]
            c_row=[c_row[i] for i in range(9) if c_row[i]!="."]
            s_row=set(c_row)
            if len(c_row)!=len(s_row):
                return False

        #check the cols
        for i in range(9):
            curr_col=[]
            col_i=i
            for k in range(9):
                num=board[k][col_i]
                if num!='.':
                    curr_col.append(num)
            s_col=set(curr_col)
            if len(s_col)!=len(curr_col):
                return False
        
        #check grids
        for r in range(0, 9, 3):
            for c in range(0, 9, 3):
                lis=[]
                for rd in range(3):
                    for rc in range(3):
                        num=board[r+rd][c+rc]
                        if num!='.':
                            lis.append(num)
                s_lis=set(lis)
                if len(s_lis)!=len(lis):
                    return False
        return True
