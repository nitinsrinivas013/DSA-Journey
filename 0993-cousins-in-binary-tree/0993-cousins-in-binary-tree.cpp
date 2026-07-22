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

        queue<TreeNode*> q;
        q.push(root);
        int currDepth = 0;

        int xDepth = -2;
        int yDepth = -2;
        bool bothFound = false;

        unordered_map<int,int> mpp;

        while(!q.empty()){
            int size = q.size();
            
            while(size){
                TreeNode* node = q.front();
                q.pop();

                if(node -> val == x){
                    xDepth = currDepth;
                    if(yDepth != -2){
                        bothFound = true;
                    }
                }
                if(node -> val == y){
                    yDepth = currDepth;
                    if(xDepth != -2){
                        bothFound = true;
                    }
                }

                if(bothFound){

                    bool sameParent = (mpp[x] != mpp[y]);

                    if(xDepth == yDepth && sameParent){
                        return true;
                    }
                    else{
                        return false;
                    }
                }

                if(node -> left){
                    q.push(node -> left);
                    mpp[node -> left -> val] = node -> val;
                }
                if(node -> right){
                    q.push(node -> right);
                    mpp[node -> right -> val] = node -> val;
                }
                size--;
            }
            currDepth++;
        }
        return false;
    }
};