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

TreeNode* rightinleft(TreeNode* root )
{
    if(root->right==NULL)
        return root;
    TreeNode* r=rightinleft(root->right);
    return r;
}
void flatten(TreeNode* root) {
    if(root==NULL || (root->left==NULL && root->right==NULL) )
        return ;
    
    TreeNode* rm,*next;
    while(root)
    {
        if(root->left)
        {
            next=root->right;
            rm=rightinleft(root->left);
            root->right=root->left;
            root->left=NULL;
            rm->right=next;
        }
        root=root->right;
    }
    
    
}
};