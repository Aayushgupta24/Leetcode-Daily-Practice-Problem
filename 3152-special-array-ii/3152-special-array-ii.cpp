class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size() ; 
         vector<bool>ans ;  
         vector<int>vec ; 
        for ( int i = 0; i < n -1; i++) { 
             if((nums[i]%2) == (nums[i+1]%2))
              vec.push_back(i) ; 
        }
             for(auto i : queries) { 
               int from  = i[0] ; 
               int to = i[1] - 1 ; 
               auto it  = lower_bound(vec.begin() , vec.end() , from)  ; 
               if (it != vec.end() &&  *it <= to) ans.push_back(false) ; 
           else ans.push_back(true) ;  
             
        }
        return ans ; 
    }
};