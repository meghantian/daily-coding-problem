# This question was asked by BufferBox.

# Given a binary tree where all nodes are either 0 or 1, prune the tree so that subtrees containing all 0s are removed.
class TreeNode:
    def __init__(self, val) -> None:
        self.val = val
        self.left = None
        self.right = None

def Inorder(root:TreeNode) -> None:
    if(root == None):
        return None
    Inorder(root.left)
    print(root.val)
    Inorder(root.right)

def PruneTree(root:TreeNode) -> TreeNode:
    if(root == None):
        return None
    root.left = PruneTree(root.left)
    root.right = PruneTree(root.right)
    if(root.val == 0 and root.left == None and root.right == None):
        return None
    return root

if __name__ == '__main__':
    '''
           1
         /   \
       0      1
      / \    /  \
    0    0  0    1
    '''
    root = TreeNode(1)
    root.left = TreeNode(0)
    root.right = TreeNode(1)
    root.left.left = TreeNode(0)
    root.left.right = TreeNode(0)
    root.right.left = TreeNode(0)
    root.right.right = TreeNode(1)
    Inorder(PruneTree(root))





    

