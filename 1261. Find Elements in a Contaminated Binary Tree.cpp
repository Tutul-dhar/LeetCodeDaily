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
#include <vector>  
using namespace std;
class FindElements {
public:
    const int p = 1000100;
    vector<int> exit;
    void recover(TreeNode* root, int val) {
        if(!root) return;
        if(val < p) exit[val] = 1;
        recover(root->left,2*val+1);
        recover(root->right,2*val+2);
    }
    FindElements(TreeNode* root) {
        exit.resize(p,0);
        recover(root,0);
    }
    
    bool find(int target) {
        return (target < p and exit[target]);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
