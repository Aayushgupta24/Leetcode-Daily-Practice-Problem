class Solution {
public: 
  int binary(vector<vector<int>>&items , int target) { 
        int left = 0 ; 
        int right = items.size() -1 ; 

        int max_beauty = 0 ; 

        while (left <= right) { 
             int mid = left + (right - left)/2 ; 

             if(items[mid][0] > target) 
             right = mid -1 ; 

             else { 
                 max_beauty = max(max_beauty , items[mid][1]) ; 
                left= mid +1 ; 
             }
        }
        return max_beauty ; 
  }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
          
          vector<int>ans(queries.size()) ; 

          sort(items.begin() , items.end() , [](vector<int>&a , vector<int>&b) { 
            return a[0] < b[0] ; }) ; 
           int max_beauty = items[0][1] ; 

           for ( int i = 0 ; i < items.size() ; i++) { 
             max_beauty= max(max_beauty , items[i][1]) ; 
             items[i][1] = max_beauty ; 
           }

           for ( int i = 0 ; i < queries.size() ; i++) 
            ans[i] = binary(items , queries[i]) ; 
        return ans ; 
    }
};