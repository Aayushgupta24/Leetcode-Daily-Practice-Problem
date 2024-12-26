class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = accumulate(nums.begin(), nums.end() ,   0 ) ; 


        vector<vector<int>>dp(nums.size() , vector<int>(2*totalsum +1 ,0)) ; 

        dp[0][nums[0] + totalsum] = 1 ; 

        dp[0][-nums[0] + totalsum] += 1 ; 
         
         for ( int i = 1 ; i <  nums.size() ; i++) {

            for ( int sum = -totalsum ; sum <= totalsum ; sum++) { 

                if (dp[i-1][sum + totalsum] > 0) {
                dp[i][sum  + nums[i] + totalsum] += dp[i-1][sum+totalsum] ; 
                dp[i][sum - nums[i] + totalsum] += dp[i-1][sum+ totalsum] ; 
            }
         }
         }
         return abs(target) > totalsum ? 0 : dp[nums.size()-1][target + totalsum]; 
            }
};