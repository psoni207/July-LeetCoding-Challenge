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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();
        if(n == 0){
            return NULL;
        }
        
        unordered_map<int,int> umap;
        int postInd = n-1;

        for(int i = 0; i < n; i++){
            umap[inorder[i]] = i;
        }
        
        TreeNode* root = constructTree(postorder,0,n-1,umap,postInd);

        return root;
    }
    
    TreeNode* constructTree(vector<int> &postorder,int low, int high, unordered_map<int,int> &umap, int postInd){
        if(low > high || postInd < 0){
            return NULL;
        }

        int item = postorder[postInd];
        TreeNode* node = new TreeNode(item);

        if(low == high){
            return node;
        }

        int ind = umap[item];

        node->left = constructTree(postorder, low, ind -1, umap, postInd-1+ind-high);
        node->right = constructTree(postorder, ind + 1, high, umap, postInd-1);

        return node;

    }
};