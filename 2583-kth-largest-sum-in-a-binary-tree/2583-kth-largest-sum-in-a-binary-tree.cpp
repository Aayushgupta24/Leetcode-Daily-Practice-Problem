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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>ans; 

        queue<TreeNode*>q ; 

        q.push(root) ; 

        while(!q.empty()){ 

          long long n = q.size() , sum = 0 ; 
          for (int i  = 0;  i < n ; i++) { 
          
              TreeNode* temp = q.front() ; 
              q.pop() ; 

              if(temp -> right) 
              q.push(temp -> right) ; 

              if (temp -> left)
                   q.push(temp -> left) ; 

                   sum += temp -> val ; 
          }
          ans.push_back(sum) ; 
        }
        sort(ans.begin() , ans.end()) ; 
        int n1 = ans.size() ; 

           return ( n1 >= k) ? ans[n1-k] : -1 ;    

        }
    
};