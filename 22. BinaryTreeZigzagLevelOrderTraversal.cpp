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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL){
            return res;
        }else{
            bool leftToRight = true;
            
            stack<TreeNode*> currlevel;
            stack<TreeNode*> nextlevel;
            
            currlevel.push(root);
            
            while(!currlevel.empty()){
                
                vector<int> ans;
                int count = currlevel.size();
                
                while(count){
                    
                    TreeNode* node = currlevel.top();
                    currlevel.pop();
                    
                    ans.push_back(node->val);
                    
                    if(leftToRight){
                        
                        if(node->left){
                            nextlevel.push(node->left);
                        }
                        if(node->right){
                            nextlevel.push(node->right);
                        }
                    }else{
                        
                        if(node->right){
                            nextlevel.push(node->right);
                        }
                        if(node->left){
                            nextlevel.push(node->left);
                        }
                    }
                    
                    count -= 1;
                }
                
                leftToRight = !leftToRight;
                swap(currlevel,nextlevel);
                
                res.push_back(ans);
                
            }
        }
        
        return res;
    }
};