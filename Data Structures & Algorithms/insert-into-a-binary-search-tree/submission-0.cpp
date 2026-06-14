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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* parent = nullptr;
        TreeNode* curr = root;
        TreeNode* newnode = new TreeNode(val);
        newnode->val = val;
        if(root == nullptr){
            return newnode;
        }

        while(curr != nullptr){
            if(val < curr->val){
                parent = curr;
                curr = parent->left;
            }else if(val > curr->val){
                parent = curr;
                curr = parent->right;
            }else{
                return root;
            }
        }
        if(val > parent->val){
            parent->right = newnode;
        }else{
            parent->left = newnode;
        }
        return root;
    }
};