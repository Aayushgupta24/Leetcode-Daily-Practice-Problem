class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        

        int n = nums.size() ;  
        while(k--) { 
        int min_ind = 0  ; 
        
         for( int i = 0 ; i < n ; i++) { 
             if(nums[i] < nums[min_ind]) 
             min_ind = i ; 
         }
      nums[min_ind] *= multiplier ; 


        }
        return nums ; 
    }
};