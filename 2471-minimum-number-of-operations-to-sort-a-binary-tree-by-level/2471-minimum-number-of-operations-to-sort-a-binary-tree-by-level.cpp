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
      int getmin(vector<int>&original) { 
         int swaps = 0 ; 
         vector<int>target = original; 

         sort(target.begin() , target.end()) ; 

         unordered_map<int,int>pos ; 

         for ( int i=  0 ;i < original.size() ; i++) { 
            pos[original[i]] = i ; 
         } 

         for ( int i = 0; i < original.size() ; i++) { 
            if (original[i] != target[i]) {
            swaps++ ; 

            int currpos = pos[target[i]] ; 
            pos[original[i]] = currpos ; 
            swap(original[currpos] ,  original[i]) ; 
         }
         }
return swaps ; 
}


    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q ; 

         q.push(root) ; 
          int swaps = 0 ; 

          while (!q.empty()) { 
             int level = q.size() ; 
              vector<int>levelval(level) ; 

              for ( int i = 0 ;i  < level ; i++) { 
                TreeNode* node = q.front() ; 
                q.pop() ; 

                levelval[i] = node -> val ; 

                if (node -> left != NULL) q.push(node -> left) ; 

                if(node -> right != NULL) q.push(node -> right) ; 

              } 
             swaps += getmin(levelval) ; 
          }
          return swaps  ;
    }
};