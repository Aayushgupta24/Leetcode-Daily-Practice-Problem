class Solution {
    public int[] resultsArray(int[] nums, int k) {
         int n = nums.length ; 

        int[] ans =  new int[n-k+1] ;

        for(int i  = 0 ; i  <= n - k ; i++) { 
             boolean is_cons  =  true ; 


             for ( int j = i ; j < i + k -1; j++) { 
                 
                 if (nums[j+1] != nums[j] +1) { 
                     is_cons = false ; 
                     break ; 
                 }
             }
             if(is_cons) 
             ans[i] = nums[i+ k -1] ; 

             else 
              ans[i] =  -1 ; 
        }
        return ans ; 
    }
}