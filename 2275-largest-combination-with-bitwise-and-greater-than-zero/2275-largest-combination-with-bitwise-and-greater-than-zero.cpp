class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi = 0 ; 

        for ( int i =0 ; i < 24 ; i++) { 
              int  cnt = 0 ; 
             for (int it : candidates) { 
                 if ((it & (1 <<  i)) != 0) 
                 cnt++  ; 
             }
             maxi = max(maxi , cnt) ; 
        }
        return maxi ; 
    }
};