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
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> output;
        vector<int> result;
        if(root != nullptr){
            output.push_back(root);
        }
        while(output.size() != 0){
            int sz = output.size();
            for(int i = 0; i < sz; i++){
                TreeNode* curr = output.back();
                output.pop_back();
                if(i == 0){
                    result.push_back(curr->val);
                }
                if(curr->right != nullptr){
                    output.push_front(curr->right);
                }
                if(curr->left != nullptr){
                    output.push_front(curr->left);
                }
            }
        }
        return result;
    }   
};