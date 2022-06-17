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
    
    int ans = 0;
    
    int minCameraCover(TreeNode* root) {
        
        int k = dfs(root);
        if(k==0)ans++;
        return max(1,ans);
        
    }
    
    int dfs(TreeNode* root)
    {
        cout<<"dfs call"<<endl;
        if(root==NULL)return 1;
        
        auto left_c = dfs(root->left);
        auto right_c = dfs(root->right);
        
        if(left_c==0 or right_c==0)
        {
            ans+=1;
            return 2;
        }
        
        if(left_c==2 or right_c==2)return 1;
        
        return 0;
    }
};