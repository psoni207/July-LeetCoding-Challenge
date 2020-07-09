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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int res = 1;
        queue<pair<TreeNode*, int> > level;
        
        level.push({root, 0});
        
        while(!level.empty()){
            int count = level.size();
            
            int start = level.front().second;
            int end = level.back().second;
            
            res = max(res, end-start+1);
            
            while(count != 0){
                TreeNode* curr = level.front().first;
                int ind = level.front().second - start;
                level.pop();
                
                if(curr->left){
                    level.push({curr->left,2*ind+1});
                }
                if(curr->right){
                    level.push({curr->right,2*ind+2});
                }
                
                count -= 1;
            }
        }
        
        return res;
        
    }
};