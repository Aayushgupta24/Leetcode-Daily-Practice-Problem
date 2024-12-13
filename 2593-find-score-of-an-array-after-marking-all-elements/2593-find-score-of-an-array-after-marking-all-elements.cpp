class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size() ; 
          vector<bool>marked(n , false) ; 
           priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq  ; 


        for ( int i = 0 ; i < n ; i++) {
             pq.push({nums[i] , i}) ; 
        }
         long long ans = 0 ; 

         while (!pq.empty()) { 
             int value = pq.top().first ; 
             int index  = pq.top().second ; 
             pq.pop() ; 

             if (marked[index]) continue ; 

             ans += value ; 

             for ( int j = index -1 ; j  <= index +1 ; j++) { 
                   if ( j >= 0 && j < n ) 
                   marked[j] = true ; 
             }
         }
         return ans ;
    }
};