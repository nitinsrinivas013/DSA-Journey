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
    vector<double> averageOfLevels(TreeNode* root) {

        vector <double> average;

        if(root == nullptr){
            return average;
        }
        queue <TreeNode*> q;
        q.push(root);

        

        while(!q.empty()){
            int size = q.size();
            int totalNodes = q.size();
            
            double sum = 0;

            while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(node -> left){
                    q.push(node -> left);
                }
                if(node -> right){
                    q.push(node -> right);
                }
                sum += node -> val;
            }
            double avg = sum/totalNodes;
            average.push_back(avg);
        }
        return average;
    }
};