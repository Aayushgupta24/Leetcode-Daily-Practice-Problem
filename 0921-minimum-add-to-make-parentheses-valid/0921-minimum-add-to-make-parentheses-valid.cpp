class Solution {
public:
    int minAddToMakeValid(string s) {
        int len = s.size() ; 

        if( len == 0) 
        return 0 ; 
        stack<char>st ; 
        int cnt = 0 ;  int cnt1 = 0 ; 
        for(int i = 0; i < len; i++) { 
         if( s[i] == '(') 
         cnt1++ ; 

         else 
          cnt1-- ; 

          if (cnt1 < 0) { 
            cnt += abs(cnt1) ; 
            cnt1 = 0 ; 
          }
            

        }       

       cnt += abs(cnt1) ; 

      return cnt ; 
    }
};