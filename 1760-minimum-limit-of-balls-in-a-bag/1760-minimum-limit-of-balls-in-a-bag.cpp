class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size() ;
        int ans = 0 ; 
         int maxi = INT_MIN ; 
          
         for (auto it : nums) 
          maxi = max(maxi , it) ; 
         
      int start = 1 ; 
      int end =  maxi ; 
        while (end >= start) { 
          int mid = start + (end - start)/2 ; 
          int cnt = 0 ; 

          for (int k = 0; k < nums.size() ; k++) { 
              cnt += (nums[k]/mid) ; 
              if(nums[k]%mid == 0) 
              cnt-- ; 
          } 
          if(cnt <= maxOperations) { 
             ans = mid ; 
              end = mid -1 ; 
          } 
          else {
             start = mid +1 ; 
          }
        }

        return ans ; 
    }
};