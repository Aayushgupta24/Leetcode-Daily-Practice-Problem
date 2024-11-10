class Solution { 
    private : 
       void update(vector<int>&cnt , int number , int delta) { 
        for ( int i = 0 ;i < 32 ; i++) { 
             if ((number >> i )&  1) 
             cnt[i] += delta ; 
        }
   }
    int convert (const vector<int>&bits) { 
         int res = 0 ; 
         for ( int i = 0 ; i < 32 ; i++) { 
             if (bits[i] != 0) 
             res |= 1 << i  ; 
         }
         return res ; 
    }


public:


    int minimumSubarrayLength(vector<int>& nums, int k) {
         int min_length = INT_MAX ; 
         int start= 0 , end = 0  ; 

         vector<int>bits(32, 0) ; 

         while (end < nums.size()) { 
             update(bits , nums[end] , 1) ; 

             while (start <=  end && convert(bits) >= k) { 
                 min_length = min(min_length , end - start +1) ;

                 update(bits , nums[start] , -1) ; 
                 start++ ; 
             }
             end++ ;
         }
         return min_length == INT_MAX ? -1 : min_length ; 
    }
};