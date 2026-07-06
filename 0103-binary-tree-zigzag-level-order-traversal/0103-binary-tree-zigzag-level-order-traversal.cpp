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

        vector<vector<int>> result;

        if(root == nullptr){
            return result;
        }
        queue <TreeNode*> q;
        q.push(root);

        
        bool flag = true;

        while(!q.empty()){
            int size = q.size();
            int size2 = q.size();
            vector<int> levels(size);
            

            while(size){
                TreeNode* node = q.front();
                q.pop();

                if(node -> left){
                    q.push(node -> left);
                }
                if(node -> right){
                    q.push(node -> right);
                }

                if(!flag){
                    levels[size - 1] = node -> val;
                }
                else{
                    levels[size2 - size] = node -> val;
                    
                }
                size--;
            }
            result.push_back(levels);
            flag = !flag;
        }
        return result;
    }
};