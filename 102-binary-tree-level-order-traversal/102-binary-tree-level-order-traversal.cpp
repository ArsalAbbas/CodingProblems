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
        vector<vector<int>>ans;
        //Edge case
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        //push root into queue
        q.push(root);
        while(!q.empty()){
            //get size of current row
            int rowSize=q.size();
            vector<int>currentRow;
            //push all the elements into current row
            for(int i=0;i<rowSize;i++){
                TreeNode* currNode=q.front();
                //push current Node value into current row
                currentRow.push_back(currNode->val);
                //push left child into the queue
                if(currNode->left)q.push(currNode->left);
                //push right child into the queue
                if(currNode->right)q.push(currNode->right);
                q.pop();
            }
            ans.push_back(currentRow);  //push current row into answer
        }
        return ans;
    }
};