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

        
        vector<vector<int>> answer;

        if(root == nullptr){
            return answer;
        }
        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector <int> levels;
            int size = q.size();

            while(size > 0){
                TreeNode* current = q.front();
                q.pop();
                levels.push_back(current -> val);

                if(current -> left){
                    q.push(current -> left);
                }
                if(current -> right){
                    q.push(current -> right);
                }
                size--;
            }
            answer.push_back(levels);
        }
        reverse(answer.begin(), answer.end());
        return answer;
        
    }
};