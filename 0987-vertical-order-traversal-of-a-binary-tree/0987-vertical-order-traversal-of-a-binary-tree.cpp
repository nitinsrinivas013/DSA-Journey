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

    void dfsTraversal
    (
        TreeNode* root,  
        map <int, map <int, multiset<int>>>& mpp,
        int x,
        int y
    ){
        if(root == nullptr){
            return;
        }
        dfsTraversal(root -> left, mpp, x - 1, y + 1);
        mpp[x][y].insert(root -> val);
        dfsTraversal(root -> right, mpp, x + 1, y + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> result;

        map <int, map <int, multiset<int>>> mpp;
        int x = 0;
        int y = 0;

        if(root == nullptr){
            return result;
        }

        dfsTraversal(root,mpp,x,y);

        for(auto it: mpp){
            vector <int> levels;
            for(auto level : it.second){

                for(int val: level.second){
                    levels.push_back(val);
                }

            }
            result.push_back(levels);
        }
        return result;
    }
};