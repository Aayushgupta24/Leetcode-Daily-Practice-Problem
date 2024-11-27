class Solution {
public: 
    int func(vector<vector<int>>&adj , int n ) { 


         vector<int>dp (n) ; 
         dp[n-1]  = 0 ; 
         for ( int i  = n -2 ; i >= 0 ; i--) { 
             int mini =  n   ; 

             for (auto it : adj[i]) { 
                 mini = min(mini , dp[it] +1 ) ; 
             }
              dp[i] = mini ; 
         }
         return dp[0] ; 
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans ; 
        vector<vector<int>>adj(n , vector<int>(0)) ; 

        for ( int i = 0 ; i < n -1 ; i++) 
        adj[i].push_back(i+1) ; 

        for (auto &it : queries) {
             int u = it[0] ; 
             int v = it[1] ; 

             adj[u].push_back(v) ; 

             ans.push_back(func(adj, n))  ; 
        }
        return ans ; 
    }
};