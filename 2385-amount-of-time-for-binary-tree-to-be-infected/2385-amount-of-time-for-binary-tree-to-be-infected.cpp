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

    void parentStoring(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mpp){

        if(root == nullptr){
            return;
        }
        if(root -> left){
            mpp[root -> left] = root;
        }
        if(root -> right){
            mpp[root -> right] = root;
        }
        parentStoring(root -> left, mpp);
        parentStoring(root -> right, mpp);

    }

    TreeNode* startNode(TreeNode* root, int start){

        if(root == nullptr){
            return nullptr;
        }
        if(root -> val == start){
            return root;
        }
        TreeNode* left = startNode(root -> left, start);

        if(left != nullptr){
            return left;
        }
        return startNode(root -> right, start);

    }

    int amountOfTime(TreeNode* root, int start) {
        
        if(root == nullptr){
            return 0;
        }

        TreeNode* target = startNode(root, start);
        
        queue<TreeNode*> q;
        q.push(target);
        unordered_map <TreeNode*, TreeNode*> mpp;
        parentStoring(root, mpp);
        unordered_map <TreeNode*, bool> visited;

        visited[target] = true;

        int minute = 0;
        

        while(!q.empty()){
            int size = q.size();
            bool spread = false;

            while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(node -> left && !visited[node -> left]){
                    visited[node -> left] = true;
                    q.push(node -> left);
                    spread = true;
                }
                if(node -> right && !visited[node -> right]){
                    visited[node -> right] = true;
                    q.push(node -> right);
                    spread = true;
                }
                if(mpp.find(node) != mpp.end() && !visited[mpp[node]]){
                    visited[mpp[node]] = true;
                    q.push(mpp[node]);
                    spread = true;
                }
            }
            if(spread){
                minute++;
            }
        }
        return minute;
    }
};