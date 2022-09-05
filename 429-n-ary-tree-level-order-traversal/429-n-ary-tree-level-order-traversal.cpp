/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
         vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<Node*> q1;
        q1.push(root);
        while(!q1.empty())
        {
            vector<int> temp;
            int size = q1.size();
            while(--size >= 0)
            {
                Node* t1 = q1.front(); q1.pop();
                 temp.push_back(t1->val);
                for(auto it : t1->children)
                    q1.push(it);
                
            }
            ans.push_back(temp);
        }
        return ans;
    }
};