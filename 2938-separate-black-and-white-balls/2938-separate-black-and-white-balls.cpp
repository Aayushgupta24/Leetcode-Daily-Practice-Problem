class Solution {
public:
    long long minimumSteps(string s) {
        long long zero = 0; 

        for(auto it : s) {
             if (it == '0') 
             zero++ ; 
        }

        long long ans =0 ,curr = 0  ; 

        for ( int i = 0 ;i < s.size(); i++) { 
             if (s[i] == '0') 
            {  ans += (i -curr) ; 
              curr++ ; }
        }
        return ans ; 
    }
};