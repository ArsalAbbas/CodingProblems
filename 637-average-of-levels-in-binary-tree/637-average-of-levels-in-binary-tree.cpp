class Solution {
public:
    vector<double> final_ans;
    
    void one_level_average(vector<TreeNode*> old)
    {
        vector<TreeNode*> new_v;
        int count = 0;
        double sum = 0;
        for (auto it = old.begin(); it!=old.end(); it++)
        {
            if ((*it)==NULL) {continue;}
            new_v.push_back((*it)->left);
            new_v.push_back((*it)->right);
            sum = sum + (*it)->val ;
            count++;
        }
        if (!count) {return;}
        final_ans.push_back(sum/count);
        one_level_average(new_v);
        return;   
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<TreeNode*> v;
        v.push_back(root);
        one_level_average(v);
        return final_ans;        
    }
};