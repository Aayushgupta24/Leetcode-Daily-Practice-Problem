class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ; 
        int m = matrix[0].size() ; 
        long long sum = 0 ; 
        int mini = INT_MAX; 
        int cnt = 0 ; 

        for(auto i : matrix) { 
             
             for (int it : i ) { 
                sum += abs(it) ; 

                if (it < 0) 
                cnt++ ; 

                mini = min(mini , abs(it)); 
             }
        }
        if(cnt%2 != 0) 
        sum -=  2*mini ; 
        return sum  ; 
    }
};