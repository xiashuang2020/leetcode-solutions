class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        s = []

        def dfs(r: TreeNode):
            if not r:
                return
            if r.left:
                dfs(r.left)
            s.append(r.val)
            if r.right:
                dfs(r.right)

        dfs(root)
        return s[k - 1]