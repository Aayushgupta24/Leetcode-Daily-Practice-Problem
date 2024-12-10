class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int>cnt ; 

          int len =0 ; 

          for ( int i  = 0 ; i < s.length() ; i++) { 
             char ch = s[i] ; 

             len = 0 ;    

             for ( int j = i ; j < s.length() ; j++) { 
                 if(ch == s[j]) { 
                    len++ ; 
                    cnt[{ch , len}]++  ; 
                 }
                 else break  ;
             }
          } 
            int ans = 0 ; 
            for (auto i  : cnt) { 
                 int len = i.first.second ; 

                 if (i.second >= 3 && len > ans) ans = len ; 
            }
            if (ans == 0 ) return -1  ; 

            return ans ; 
    }
};