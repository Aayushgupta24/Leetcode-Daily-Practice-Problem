class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans(code.size() , 0) ; 

        if (k == 0) return ans ; 

        int start =  1, end =  k, sum = 0; 

        if (k < 0) { 
             start =  code.size() - abs(k) ; 
             end = code.size() -1 ; 
        } 

        for ( int i = start ; i <= end ; i++) 
        sum += code[i] ; 

        for (int i = 0 ;  i < code.size() ; i++) { 
             ans[i] = sum ; 
             sum -= code[start%code.size()] ; 
             sum += code[(end +1)%code.size()] ; 

             start++ ; 
             end++ ; 
        }
        return ans ; 
    }
};