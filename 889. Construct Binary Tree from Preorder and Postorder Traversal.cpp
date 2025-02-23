/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pre_idx = 0,post_idx = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* tree = new TreeNode(preorder[pre_idx]);
        pre_idx++;
        if(tree->val != postorder[post_idx]) tree->left = constructFromPrePost(preorder,postorder);

        if(tree->val != postorder[post_idx]) tree->right = constructFromPrePost(preorder,postorder);

        post_idx++;
        return tree;
    }
};
