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
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> output;
        vector<vector<int>> result;
        if(root != nullptr){
            output.push_back(root);
        }
        while(output.size() != 0){
            vector<int> result_sub;
            int sz = output.size();
            for(int i = 0; i < sz; i++){
                TreeNode* curr = output.front();
                output.pop_front();
                result_sub.push_back(curr->val);
                if(curr->left != nullptr){
                    output.push_back(curr->left);
                }
                if(curr->right != nullptr){
                    output.push_back(curr->right);
                }
            }
            result.push_back(result_sub);
        }
        return result;
    }
};
