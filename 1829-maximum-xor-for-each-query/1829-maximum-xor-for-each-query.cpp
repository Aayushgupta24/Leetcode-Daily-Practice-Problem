class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>ans; 

        int xor_cnt = 0 ; 

        for (auto it : nums) 
         xor_cnt = xor_cnt ^ it ; 

         int mask = pow(2 , maximumBit) -1 ; 

         int n = nums.size() ; 

         for ( int i = n-1 ; i >= 0 ; i--) { 
            ans.push_back(xor_cnt^mask) ; 
            xor_cnt ^= nums[i] ;
         }
         return ans ; 
    }
};