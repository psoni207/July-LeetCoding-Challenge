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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL){
            return res;
        }
        
        queue<TreeNode* > level;
        level.push(root);
        int count = 1;
        while( !level.empty() ){
            
            count = level.size();
            vector<int> temp;
            while(count != 0){
                TreeNode *curr = level.front();
                level.pop();

                temp.push_back(curr->val);
                
                if(curr->left){
                    level.push(curr->left);
                }
                if(curr->right){
                    level.push(curr->right);
                }
                
                count -= 1;
            }
            
            res.push_back(temp);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};