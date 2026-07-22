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
    bool isCousins(TreeNode* root, int x, int y) {

        if(root == nullptr){
            return false;
        }

        queue <TreeNode*> q;
        q.push(root);

        bool foundX = false;
        bool foundY = false;

        while(!q.empty()){
            int size = q.size();

            while(size--){

                TreeNode* node = q.front();
                q.pop();

                if(node -> left && node -> right){
                    
                    int leftValue = node -> left -> val;
                    int rightValue = node -> right -> val;

                    if((leftValue == x && rightValue == y) ||
                        (leftValue == y && rightValue == x)){

                            return false;
                        }

                }

                if(node -> val == x){
                    foundX = true;
                }
                if(node -> val == y){
                    foundY = true;
                }

                if(node -> left){
                    q.push(node -> left);
                }
                if(node -> right){
                    q.push(node -> right);
                }
            }
            if(foundX && foundY){
                return true;
            }
            if(foundX || foundY){
                return false;
            }
        }
        return false;
    }
};