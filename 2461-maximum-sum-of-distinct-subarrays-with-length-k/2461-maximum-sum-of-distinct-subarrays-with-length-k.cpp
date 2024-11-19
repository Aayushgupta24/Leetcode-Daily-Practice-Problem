class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0 ; 
       long long curr_sum = 0 ; 

       int start = 0 , end  = 0 ; 

       unordered_map<int,int>mpp ;
         
         for ( int i = 0 ;i < nums.size() ; i++) { 
             curr_sum += nums[i] ; 

             mpp[nums[i]]++ ; 

             if ( i >= k -1) { 

                 if (mpp.size() == k) 
                  ans = max(ans , curr_sum) ; 
                  curr_sum -= nums[i-k+1] ; 

                  if (--mpp[nums[i-k+1]] == 0 ) 
                  mpp.erase(nums[i-k+1]) ; 
             }
         }
         

        return ans ;
    }
};