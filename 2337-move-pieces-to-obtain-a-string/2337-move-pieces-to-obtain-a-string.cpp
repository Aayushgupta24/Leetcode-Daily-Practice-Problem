class Solution {
public:
    bool canChange(string start, string target) {
        int len = start.length() ; 
        int len2 = target.length() ; 

        if (start == target) return true ; 

        int waitl = 0 ; 
        int waitr  = 0 ; 

        for ( int i = 0 ; i < len ; i++){ 
             
             char  curr = start[i] ; 
             char goal = target[i] ; 

             if (curr == 'R') { 
                 
                 if (waitl > 0) return false ; 
                 waitr++ ; 
             } 

            if (goal == 'L') { 
                 if (waitr > 0) return false ; 
                 waitl++ ; 
            }
            if (goal == 'R') { 
                if (waitr == 0) return false ; 
                waitr-- ; 
            }
            if (curr == 'L') { 
                if (waitl == 0)return false ; 
                waitl--  ; 
            }
        }
        return waitl == 0 && waitr == 0 ; 
    }
};