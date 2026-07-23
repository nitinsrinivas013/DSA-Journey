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

    bool isLeaf(TreeNode* root){
        if(root == nullptr){
            return false;
        }
        return root -> left == nullptr && root -> right == nullptr;
    }

    void helper(TreeNode* root, vector<int> &leaves){
        if(root == nullptr){
            return;
        }
        if(isLeaf(root)){
            leaves.push_back(root -> val);
        }
        helper(root -> left, leaves);
        helper(root -> right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> leaves1;
        vector<int> leaves2;

        helper(root1, leaves1);
        helper(root2, leaves2);

        return leaves1 == leaves2;

    }
};