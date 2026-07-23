/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void storingParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mpp){

        if(root == nullptr){
            return;
        }
        if(root -> left){
            mpp[root -> left] = root;
        }
        if(root -> right){
            mpp[root -> right] = root;
        }
        storingParent(root -> left, mpp);
        storingParent(root -> right, mpp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> result;
        if(root == nullptr){
            return result;
        }

        unordered_map <TreeNode*, TreeNode*> mpp;
        storingParent(root,mpp);
        unordered_map <TreeNode*, bool> visited;

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int distance = 0;

        

        while(!q.empty()){

            int size = q.size();
            

            if(distance == k){
                break;
            }

            while(size--){
                TreeNode* node = q.front();
                q.pop();

                
                if(node -> left && !visited[node -> left]){

                    visited[node -> left] = true;
                    q.push(node -> left);
                    
                }
                if(node -> right && !visited[node -> right]){
                    visited[node -> right] = true;
                    q.push(node -> right);
                   
                }
                if(mpp.find(node) != mpp.end() && !visited[mpp[node]]){

                    visited[mpp[node]] = true;
                    q.push(mpp[node]);
                    
                }
                
            }
            distance++;
        }

        while(!q.empty()){
            result.push_back(q.front() -> val);
            q.pop();
        }
        return result;
    }
};