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
        int currentLevel = 0;

        while(!q.empty()){
            int size = q.size();
            int i = 0;
           
            int index = 0;
            vector<int> levels(size);
            int n = size;

            while(size > 0){
                
                TreeNode* current = q.front();
                q.pop();
                if(currentLevel % 2 == 0){
                    index = i;
                }
                else{
                    index = n-i-1;
                }
                levels[index] = current -> val;
                if(current -> left){
                    q.push(current -> left);
                }
                if(current -> right){
                    q.push(current -> right);
                }
                size--;
                i++;
                
            }
            answer.push_back(levels);
            currentLevel++;
        }
        return answer;
    }
};