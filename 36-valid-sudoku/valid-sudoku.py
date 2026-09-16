class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        dic_r=defaultdict(set)
        dic_c=defaultdict(set)
        dic_s=defaultdict(set)

        for r in range(9):
            for c in range(9):
                row=board[r]
                num=row[c]
                if num=='.':
                    continue
                
                if num in dic_r[r]:
                    return False
                dic_r[r].add(num)

                if num in dic_c[c]:
                    return False
                dic_c[c].add(num)

                id=(r/3)*3+c/3
                if num in dic_s[id]:
                    return False
                dic_s[id].add(num)
        return True