class Solution {
public:
    char findKthBit(int n, int k) {
       int cnt  = 0 ; 
        
        int len = (1 << n) - 1 ; 
        
        while( k > 1) { 
         if( k == len/2 +1) 
             return  cnt%2 == 0 ? '1' : '0' ; 
            
        
        
        if( k > len/2) { 
          k = len + 1 - k ; 
            cnt++ ; 
        }
        len /= 2 ; 
        
    }
        return cnt%2 == 0 ? '0' : '1' ; 
    }
};