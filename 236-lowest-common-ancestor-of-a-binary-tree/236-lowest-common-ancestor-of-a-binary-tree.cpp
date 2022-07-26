class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root->val == p->val || root->val == q->val)
            return root;
        if (root->left == NULL && root->right == NULL)
            return NULL;
        TreeNode *left = NULL, *right = NULL;
        if (root->left)
            left = lowestCommonAncestor(root->left, p, q);
        if (root->right)
            right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        if (left == NULL)
            return right;
        else
            return left;
    }
};