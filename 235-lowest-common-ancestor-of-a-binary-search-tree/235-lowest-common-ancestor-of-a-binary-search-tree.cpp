/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp=root;
        while(temp)
        {
            if((temp->val > p->val && temp->val < q->val) || (temp->val < p->val && temp->val > q->val) || temp->val==p->val || temp->val==q->val)
            {
                break;
            }
            else if(temp->val < p->val && temp->val < q->val)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }
        }
        return temp;
    }
};