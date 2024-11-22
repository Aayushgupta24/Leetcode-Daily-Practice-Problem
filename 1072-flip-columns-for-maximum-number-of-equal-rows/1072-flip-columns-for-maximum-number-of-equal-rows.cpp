class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
       int maxi = 0;  
        int m = matrix[0].size() ; 

       for (auto& it : matrix) { 
        vector<int>flipped_row(m) ; 
        int cnt = 0 ; 

        for ( int j = 0 ; j < m ; j++) { 
             flipped_row[j] = 1 -  it[j] ; 
        } 

        for (auto &it1 : matrix) { 
             if (it1 == it || it1 == flipped_row) 
             cnt++  ; 
        }  
        maxi = max(maxi , cnt) ;
       }
       return maxi ; 
    }
};