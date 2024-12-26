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

    TreeNode* reverseOddLevels(TreeNode* root) {  
       if(root == NULL) return NULL ; 

        queue<TreeNode*>q ; 
        q.push(root) ; 
        int level =  0 ; 

         while(!q.empty()) { 
             int size  = q.size() ; 
              vector<TreeNode*>curr ; 
               
               for ( int i = 0; i < size ; i++) { 
                 TreeNode* node = q.front() ; 
                 q.pop() ;  
                 curr.push_back(node) ; 

                  if (node -> left) q.push(node -> left) ; 
                  if (node -> right) q.push(node -> right) ; 
               } 
               if(level%2 == 1) { 
                  int left = 0 , right = curr.size() -1 ; 

                   while (left < right) { 
                     int temp = curr[left] -> val ; 
                      curr[left] -> val = curr[right] -> val  ; 
                      curr[right] -> val = temp ; 
                     left++ ; 
                     right-- ; 
                   }
               }
               level++ ; 
         }
return root ; 

    }
};