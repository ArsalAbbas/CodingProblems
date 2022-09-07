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
    string tree2str(TreeNode* root) {
        
        //if there is no root return empty string
        if(!root){
            return "";
        }
        
        
        //store the root value in the string
        string ans = to_string(root->val);
        
        
        //if there exists a left of right child 
        if(root->left || root->right){
            ans += "(" + tree2str(root->left) + ")";
            
            
            //if there exists a right child.
            if(root->right){
                ans+= "(" + tree2str(root->right) + ")";
            }
        }
        
        
        return ans;
        
    }
};