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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> result;

        if(root == nullptr){
            return result;
        }

        queue <pair <TreeNode*, pair<int,int>>> q;
        map <int, map <int, multiset<int>>> mpp;
        q.push({root, {0,0}});

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto element = q.front();
                q.pop();
                TreeNode* node = element.first;
                int x = element.second.first;
                int y = element.second.second;

                if(node -> left){
                    q.push({node -> left, {x-1, y+1}});
                }
                if(node -> right){
                    q.push({node -> right, {x+1, y+1}});
                }
                mpp[x][y].insert(node -> val);
            }
        }
        for(auto it : mpp){
            vector<int> levels;
            for(auto level : it.second){
                for(int val : level.second){
                    levels.push_back(val);
                }
            }
            result.push_back(levels);
        }
        return result;
    }
};