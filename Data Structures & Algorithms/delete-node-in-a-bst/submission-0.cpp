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
    TreeNode* deleteNode(TreeNode* root, int val) {
        TreeNode* parent = root;
        
        if(root == nullptr){
            return nullptr;
        }
        if(val > root->val){
            root->right = deleteNode(root->right, val);
        }else if(val < root->val){
            root->left = deleteNode(root->left, val);
        }else{
            if(root->left == nullptr){
                return(root->right);
            }else if(root->right == nullptr){
                return(root->left);
            }else{
                TreeNode* minnode = findMin(root->right);
                root->val = minnode->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }

private:
    TreeNode* findMin(TreeNode* root){
        TreeNode* curr = root;
        while(curr->left != nullptr){
            curr = curr->left;
        }
        return curr;
    }

};