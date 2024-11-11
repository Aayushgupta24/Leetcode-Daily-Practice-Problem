class Solution {
public: 


  bool isPrime(  int n ) { 
    //   int n = nums.size() ; 

       for ( int i = 2 ; i <= sqrt(n) ; i++) { 
           if (n%i == 0) 
           return 0 ; 
       }
       return 1 ; 
  }
    bool primeSubOperation(vector<int>& nums) {
         int n = nums.size() ; 
          int maxi = *max_element(nums.begin() , nums.end()) ; 

          vector<int>prime(maxi +1 , 0);  


         for ( int i = 2 ; i <= maxi ; i++) { 
              if (isPrime(i)) 
               prime[i] = i ; 

               else 
               prime[i] =  prime[i-1] ; 
         }

         for ( int i  = 0; i < nums.size() ; i++) { 
              
               int bound ; 
               if ( i == 0) 
               bound = nums[0] ; 

               else 
               bound = nums[i] - nums[i-1] ; 

               if (bound <= 0 ) 
               return 0 ; 

               int largest_prime = prime[bound -1] ; 

               nums[i] = nums[i] - largest_prime ; 
                
         }
         return -1 ; 
    }
};