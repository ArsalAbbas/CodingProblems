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
    
    void inorder(vector<int> &v, TreeNode* root, int idx) {
        if(!root) return;
        inorder(v,root->left, idx+1);
        v[idx] = root->val;
        inorder(v, root->right, idx+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v(101,-101);
        inorder(v, root, 0);
        vector<int> ans;
        int index = 0;
        while(v[index] != -101) {
            ans.push_back(v[index]);
            index += 1;
        }
        return ans;
    }
};