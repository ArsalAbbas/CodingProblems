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
/*we have to find kth smallest value so using inorder traversal and also decreasing k when k=0 it means we are at right node which value will be kth smallest element ,that's i used an int variable ans to store the val ...int k argument is reference argument so after recursive call back the value of k will not not same as it was when the function was called */
class Solution {
   
public:
    int ans;
    int kthSmallest(TreeNode* root, int &k) {
        if(root){
            kthSmallest(root->left,k);
            k--;
            if(k==0) ans=root->val;
            kthSmallest(root->right,k);
        }
        return ans;
    }
};