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
private:
    int findPosition(vector<int>& inorder, int& element, int n) {
        for(int i = 0; i < n; i++)
            if(inorder[i] == element)
                return i;
        return -1;
    }
private:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preorderIndex, int inorderStart, int inorderEnd, int n) {
        
        if(preorderIndex >= n || (inorderStart > inorderEnd))
            return NULL;
        
        int element = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(inorder, element, n);
        
        root->left = solve(preorder, inorder, preorderIndex, inorderStart, position - 1, n);
        root->right = solve(preorder, inorder, preorderIndex, position + 1, inorderEnd, n);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preorderIndex = 0;
        TreeNode* ans = solve(preorder, inorder, preorderIndex, 0, n-1, n);
        return ans;
    }
};