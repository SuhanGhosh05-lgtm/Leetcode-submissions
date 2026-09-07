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
int height(TreeNode* root){
    if(root==NULL){
         return true;
    }
    int leftdepth=height(root->left);
    int rightdepth=height(root->right);
    return max(leftdepth,rightdepth)+1;

}
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
    int leftdepth=height(root->left);
    int rightdepth=height(root->right);
    if(abs(leftdepth-rightdepth)>1){
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
    }
};