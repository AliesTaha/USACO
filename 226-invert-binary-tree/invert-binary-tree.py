# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        def help(node):
            if not node or (not node.left and not node.right):
                return
            left_child = node.left
            right_child = node.right
            help(left_child)
            help(right_child)
            node.left=right_child
            node.right=left_child
        
        help(root)
        return root
