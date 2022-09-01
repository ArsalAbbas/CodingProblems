class Solution {
public:
    int ans=0;
    void good(TreeNode* root,int maxx)
    {
        if(root!=NULL)
        {
            if(root->val>=maxx)
            {
                ans++;
                maxx=root->val;
            }
            good(root->left,maxx);
            good(root->right,maxx);
        }
    }
    int goodNodes(TreeNode* root) {
        good(root,-100000);
        return ans;
    }
};