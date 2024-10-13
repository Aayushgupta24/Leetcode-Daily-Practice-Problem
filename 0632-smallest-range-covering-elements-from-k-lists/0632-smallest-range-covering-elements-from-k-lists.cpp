class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size() ;

        vector<int>ind(n ,0) ; 
        vector<int>range = {0, INT_MAX} ; 

        while (true) { 
             int curr_min = INT_MAX , curr_max = INT_MIN , min_ind = 0 ; 

             for ( int i = 0; i < nums.size() ; i++) { 
                 int curr_ele = nums[i][ind[i]] ; 

                 if (curr_ele < curr_min) { 
                    curr_min = curr_ele ; 
                    min_ind = i ; 
                 }
                 if (curr_ele > curr_max ) 
                curr_max = curr_ele ; 
             }
         if (curr_max - curr_min < range[1] - range[0]) { 
            range[0] = curr_min ; 
            range[1] = curr_max ; 
         }

         if(++ind[min_ind] == nums[min_ind].size()) 
         break ; 

        }
        return range ; 
    }
};