// This problem was asked by Google.

// A unival tree (which stands for “universal value”) is a tree where all nodes under it have the same value.

// Given the root to a binary tree, count the number of unival subtrees.
// 当前节点要成为一个单值子树，必须满足以下条件：
//      左子树和右子树都是单值子树。
//      左右子树的值（如果存在）必须与当前节点的值相同。
// 采用后序遍历。同时我们将计数传入参数进行更新。
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
bool helper(TreeNode* root, int& cnt){
    if(root == NULL) return true;
    bool left = helper(root->left, cnt);
    bool right = helper(root->right, cnt);

    if (left == false || right == false)
       return false;
    if (root->left && root->val != root->left->val)
        return false;


    if (root->right && root->val != root->right->val)
        return false;
    cnt++;
    return true;

}
int countUnivalSubtree(TreeNode* root){
    int cnt = 0;
    helper(root, cnt);
    return cnt;

}
int main(){
    /* Let us construct the below tree
            5
          /   \
        4      5
      /  \      \
     4    4      5 */
    TreeNode* root        = new TreeNode(5);
    root->left        = new TreeNode(4);
    root->right       = new TreeNode(5);
    root->left->left  = new TreeNode(4);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
 
    cout << "Count of Single Valued Subtrees is "
         << countUnivalSubtree(root);
    return 0;
}