class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n= nums.size() ; 

        vector<pair<int,int>>ranges ; 

        int start =  INT_MAX ,  end = INT_MIN ; 

        for ( auto it : nums) { 
             int left =   it - k ; 
               int right = it + k ; 

               ranges.push_back({left, right}) ; 
                 start = min(start , left) ; 
                 end = max(end , right) ; 

        }

        unordered_map<int,int>mpp ; 

        for (auto it : ranges) { 
             int first = it.first ; 
               int second = it.second ; 

               mpp[first]++ ; 
               mpp[second+1]-- ; 
        } 
         int ans = 0 ,temp = 0 ; 

         for ( int i =start ; i <= end +1 ; i++) { 
             temp +=  mpp[i]  ; 
              ans = max(ans , temp) ; 
         }
         return ans ; 
    }
};