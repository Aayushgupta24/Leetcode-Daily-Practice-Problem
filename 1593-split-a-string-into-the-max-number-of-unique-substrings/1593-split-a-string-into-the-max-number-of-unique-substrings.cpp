class Solution {
public:
    
    void backtrack(const string& st , int s , unordered_set<string>&seen, int count , int &maxcount) {
     if (count+ (st.size() - s) <= maxcount) 
         return  ; 
        
        if (s == st.size()) { 
         maxcount = max(maxcount , count) ; 
            return ; 
        }
     for ( int i= s +1 ; i <= st.size() ; i++) {
          
         string sub_str = st.substr(s,   i-s) ;
         if (seen.find(sub_str) == seen.end()) { 
          seen.insert(sub_str) ; 
             backtrack(st , i , seen , count +1 , maxcount) ; 
             seen.erase(sub_str) ; 
         }
             
         }
         
     }
        
    
    int maxUniqueSplit(string s) {
        int n = s.length() ;
        unordered_set<string>seen ; 
        
        int max_count = 0 ;
        
        backtrack(s , 0 , seen ,0 , max_count) ;
        return max_count ; 
        
    }
};