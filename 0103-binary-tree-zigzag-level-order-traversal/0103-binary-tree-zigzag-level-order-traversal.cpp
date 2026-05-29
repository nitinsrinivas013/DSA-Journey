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

        vector<vector<int>> answer;
        if(root == nullptr){
            return answer;
        }

        queue <TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            
            vector <int> levels;

            while(size > 0){
                TreeNode* current = q.front();
                q.pop();

                levels.push_back(current -> val);

                if(level % 2 == 0){
                    if(current -> right){
                        q.push(current -> right);
                    }
                    if(current -> left){
                        q.push(current -> left);
                    }
                }
                else{
                    if(current -> left){
                        q.push(current -> left);
                    }
                    if(current -> right){
                        q.push(current -> right);
                    }
                }
                size--;
                level++;
            }
            answer.push_back(levels);
        }
        return answer;
    }
};